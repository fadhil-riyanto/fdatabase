# how to use

hack```
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . "/../src/Utils.hh");
    require(__DIR__ . '/../src/main.hh');
    $db = new fdatabase("db.fdb", dict[ // db.fdb must exist!!
        "set_load_file" => true  // this is setting, true if you want check value from database before set() method, this is
                                // will enabled if you passed the set("key", "value", false);
                                // the false bool will check from database if any key not same with target key
    ]);
    $db->set("foUoe", "bare", true); // this will saved to memory, non overwritten
    $db->commit(); // commit to file

    echo $db->get("foUoe");
}
```