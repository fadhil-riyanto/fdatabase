#!/usr/bin/env hhvm

class fdatabase
{   
    private $filename;
    private $database_variabel;
    function __construct($namefile){
        $this->filename = $namefile;
    }

    public function debug_fs() {
        echo $this->filename;
    }
    public function set(string $key, $value) {
        if($this->database_variabel != null){
            $this->database_variabel[$key] = $value;
        }
        else{
            $this->database_variabel = dict[$key => $value];
        }
    }
    public function get(string $key) {
        if(isset($this->database_variabel[$key])){
            return $this->database_variabel[$key];
        }
        else{
            $this->database_variabel = json_decode(file_get_contents($this->filename), true);
            if(isset($this->database_variabel[$key])){
                return $this->database_variabel[$key];
            }else{
                return null;
            }
        }
        // return $this->database_variabel[$key];
    }
    public function commit(){
        if(file_exists($this->filename)){
            // $this->database_variabel = json_decode(file_get_contents($this->filename));
            file_put_contents($this->filename, json_encode($this->database_variabel));
        }else{
            // $this->database_variabel = array();
            // buat file
            file_put_contents($this->filename, json_encode($this->database_variabel));
        }
    }
}

