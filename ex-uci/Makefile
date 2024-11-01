include $(TOPDIR)/rules.mk

PKG_NAME:=uci_excise
PKG_RELEASE:=1.0

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

SOURCE_DIR:=./src/

include $(INCLUDE_DIR)/package.mk

# a example to enable macro from config.in
ifeq ($(CONFIG_PACKAGE_uci_excise),y)
  TARGET_CFLAGS += -DCONFIG_HELLO_ENABLE
endif

TARGET_LDFLAGS += -luci

define Package/uci_excise
  SECTION:=uci_excise
  CATEGORY:=Examples
  TITLE:=Hello utility
  DEPENDS:=+libuci +libubox
endef

define Package/uci_excise/description
  Test uci functions.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	cp $(SOURCE_DIR)/* $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS) -Wall" \
		LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/uci_excise/install
	##$(INSTALL_DIR)  $(1)/etc/config
	##$(INSTALL_CONF) ./files/uci_excise.conf  $(1)/etc/config/hello
	##$(INSTALL_DIR)  $(1)/etc/init.d
	##$(INSTALL_BIN)  ./files/uci_excise.init  $(1)/etc/init.d/hello
	$(INSTALL_DIR)  $(1)/usr/sbin
	$(INSTALL_BIN)  $(PKG_BUILD_DIR)/uci_excise  $(1)/usr/sbin/uci_excise
endef

$(eval $(call BuildPackage,uci_excise))
