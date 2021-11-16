<?hh

class fdatabase extends futils
{   
    private $filename;
    private $database_variabel;
    function __construct($namefile){
        $this->filename = $namefile;
    }

    public function debug_fs() {
        echo $this->filename;
    }
    public function set(string $key, $value,  bool $timpa = true): bool {
        if($timpa == false){
            if(isset($this->database_variabel[$key])){
                $ditemukan = true;
            }
            else{
                $this->database_variabel = json_decode(file_get_contents($this->filename), true);
                if(isset($this->database_variabel[$key])){
                    $ditemukan = true;
                }else{
                    $ditemukan = false;
                }
                
            }
            $check_jika_ada = ($ditemukan == true) ? true : false;

            echo "debug timpa = 1";
            if($check_jika_ada){
                // cek apakah value sudah ada di database
                // if(array_key_exists($key, $this->database_variabel)){
                    //  print("Key $key sudah ada di database");
                    throw new Exception("Key $key sudah ada di database", 1);
                    
                // }else{
                //     $this->database_variabel[$key] = $value;
                //     return true;
                //     echo "di db";
                // }
            }else{
                // if(array_key_exists($key, $this->database_variabel)){
                //     print("Key $key sudah ada di database");
                // }else{
                //     $this->database_variabel[$key] = $value;
                //     return true;
                //     echo "di db";
                // }
                print("debug it");
                $this->database_variabel = dict[$key => $value];
                return true;
            }
        }else{
            if($this->database_variabel != null){
                $this->database_variabel[$key] = $value;
                return true;
            }
            else{
                $this->database_variabel = dict[$key => $value];
                return true;
            }
        }
        
        // return false;
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
