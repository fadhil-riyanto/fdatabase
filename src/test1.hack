
<?php

function main() {
    require(__DIR__ . '/main.hack');
    $db = new fdatabase("test.fdb");
    echo $db->get("umur") . "\n";
    echo $db->get("kelas");
    //$db->commit();
}
main();