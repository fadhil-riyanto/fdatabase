
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . "/../src/Utils.hh");
    require(__DIR__ . '/../src/main.hh');
    $db = new fdatabase("db.fdb", dict[
        "set_load_file" => true
    ]);
    $db->del("pepp");
    $db->commit();
    exit(0);
}