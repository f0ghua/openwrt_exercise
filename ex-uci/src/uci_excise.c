#include <glob.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <inttypes.h>
#include <uci.h>

const char *UCIEX_OP_PATH = "foo.op.name";
const char *UCIEX_SAVE_DIR = "/tmp/uciex";

static int uci_display_option(struct uci_context *ctx, const char *path)
{
	struct uci_ptr ptr;
	char *str = strdup(path);
	char *p = NULL;

	if (!uci_lookup_ptr(ctx, &ptr, str, true) 
		&& ptr.o != NULL 
		&& ptr.o->type == UCI_TYPE_STRING) {
		p = ptr.o->v.string;
	}

	printf("option %s value = %s\n", path, p? p : "NULL");
	free(str);

	return 0;
}

int main()
{
	struct uci_context *ctx = NULL;
	struct uci_package *pkg = NULL;
	struct uci_ptr ptr = {.package = "foo"};
	char *str = strdup(UCIEX_OP_PATH);
	char *p;
	int ret;

	ctx = uci_alloc_context();
	if (!ctx)
		goto out;

	uci_set_savedir(ctx, UCIEX_SAVE_DIR);
/*
	uci_load(ctx, ptr.package, &pkg);
	if (!pkg)
		goto out;
	printf("%s line %d\n", __FILE__, __LINE__);
*/
	uci_display_option(ctx, UCIEX_OP_PATH);

	const char *val = "world";	
	if (uci_lookup_ptr(ctx, &ptr, str, true)) {
		printf("uci_lookup_ptr failed\n");
		goto out;
	}
	ptr.value = val;
	ret = uci_set(ctx, &ptr);
	if (ret != UCI_OK) {
		printf("uci_set failed\n");
		goto out;
	}

	uci_display_option(ctx, UCIEX_OP_PATH);

	//uci_save(ctx, ptr.p);

	uci_unload(ctx, ptr.p);
	uci_display_option(ctx, UCIEX_OP_PATH);
	

	//uci_commit(ctx, &ptr.p, false);
out:
	if (ctx)
		uci_free_context(ctx);
	free(str);

	return 0;
}
