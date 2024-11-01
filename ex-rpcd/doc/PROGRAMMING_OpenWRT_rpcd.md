Write a rpcd plugin, register service `foo` to `ubusd`. Provide function to get/set datetime of the system.

Works as the following:

```bash
root# ubus -v list foo
'foo' @d44c8557
        "read":{}
        "write":{"date":"String"}

root# ubus call foo read
{
        "date": "2026-01-01 00:18:19"
}

root# ubus call foo write '{"date":"2026-1-1 00:00:00"}'
{
        "success": true
}
```

