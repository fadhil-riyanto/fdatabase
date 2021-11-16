
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . "/../src/Utils.hh");
    require(__DIR__ . '/../src/main.hh');
    $db = new fdatabase("db.fdb", dict[
        "set_load_file" => false
    ]);
    $db->set("foUoe1", "apaan?");
    echo $db->get("foUoe1");
    exit(0);
}