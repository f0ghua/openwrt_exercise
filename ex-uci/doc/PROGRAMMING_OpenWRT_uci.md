Write a OpenWRT package, install config file `ex-uci.config`  to `/etc/config` and binary `ex-uci` to `/usr/bin` to do the following exercises. 

The initial content of `ex-uci.config` as below

```
config device
        option name 'br-lan'
        option type 'bridge'
        list ports 'eth1'
        list ports 'eth2.1035'

config interface 'lan'
        option device 'br-lan'
        option proto 'static'
        option ipaddr '192.168.1.1'
        option netmask '255.255.255.0'
        option ip6assign '60'

config device
        option type '8021q'
        option ifname 'eth2'
        option vid '1035'
        option name 'eth2.1035'
```

## Exercise 1 - read uci

Write function `ex1_uci_read1()`  , get value of the following items with API `uci_load` and `uci_lookup_ptr` (argument `str` value must be NULL) , then print values to the terminal
- option `proto` of interface `lan` 
- list `ports` of `br-lan` device (the first `device` section)

Write function `ex1_uci_read2()` , get value of the following items with API `uci_lookup_ptr` only
- option `name` of the `vlan` device (the latest `device` section)

## Exercise 2 - write uci

Write function `ex2_uci_write()` to
- modify option `ex-uci.@device[1].name` value to `eth2.960`

## Exercise 3 - deep in the usage

Study `luci` and `rpcd` (`rpcd/uci.c`) source code related to uci get/set part, answer the following questions:

- How to operate on uci configs without impacting the system uci data (`/tmp/.uci`)?
- How to discard changes before committing data to config files?

Write function `ex3_uci_test` to prove your conclusion.
