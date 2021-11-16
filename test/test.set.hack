
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . "/../src/Utils.hh");
    require(__DIR__ . '/../src/main.hh');
    $db = new fdatabase("db.fdb", dict[
        "set_load_file" => true
    ]);
    // $db->set("pppp", "hai juga");
    // $db->set("ppp22p", "hai juga");
    // // $db->set("nama", "fadhil");
    // // $db->set("kelas", "10");
    // // var_dump($db->set("foUoe", "bar", false));
    // // var_dump($db->set("foUoe1", "bar1", false));
    // // echo $db->get("foUoe") . "\n";
    // echo $db->get("foUoe1");

    echo $db->get("foUoe");

    // $db->debug_mem();
    // $db->commit();
    exit(0);
}