
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . "/../src/Utils.hh");
    require(__DIR__ . '/../src/main.hh');
    $db = new fdatabase("db.fdb", dict[
        "set_load_file" => true
    ]);
    // $db->set("keys1", "value1");
    $db->del("keys1");
    $db->commit();
    exit(0);
}