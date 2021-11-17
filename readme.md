# how to use

```hack
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . "/../src/Utils.hh");
    require(__DIR__ . '/../src/main.hh');
    $db = new fdatabase("db.fdb", dict[ 
        "set_load_file" => true
    ]);
    $db->set("foUoe", "bare", true); 
    $db->commit(); // commit to file

    echo $db->get("foUoe");
}
```

# method

+ set(key, value, overwritten)
    - key is a identifier of value
    - value is a content
    - overwritten is condition, default is true. turn false if you not overwrite the data
+ del(key)
    - key to delete

+ commit()
    - for append data from memory to non volatile file

+ get(key)
    - getting the key

# note 
the file in construct class of fdatabase must be exist!