

<?php

function main() {
    require(__DIR__ . '/main.hack');
    $db = new fdatabase("test.fdb");
    $db->set("hai", "hai juga");
    $db->set("nama", "fadhil");
    $db->set("kelas", "10");
    $db->set("umur", "15");
    $db->commit();

    unset($db);
    $db = new fdatabase("test.fdb");
    echo $db->get("nama");
}
main();