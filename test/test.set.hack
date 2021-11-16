
<<__EntryPoint>>
function main(): noreturn {
    require(__DIR__ . '/../src/main.hack');
    $db = new fdatabase("db.fdb");
    // $db->set("hai", "hai juga");
    // $db->set("nama", "fadhil");
    // $db->set("kelas", "10");
    var_dump($db->set("foUo", "bar", false));
    var_dump($db->set("fooS", "bar", false));
    // echo $db->get("foo");
    $db->commit();
    exit(0);
}