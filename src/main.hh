<?hh

class fdatabase extends futils
{   
    private $filename, $load_dari_file_for_set;
    private $database_variabel;
    private $jsonfile_arr;

    
    function __construct($namefile, dict<bool> $config_database){
        $this->filename = $namefile;
        $this->load_dari_file_for_set = $config_database["set_load_file"];
        
    }

    public function debug_fs() {
        echo $this->filename;
    }
    public function debug_mem() {
        $jsonfile = futils::decode_json($this->filename);
        //$this->database_variabel = array_merge($jsonfile, $this->database_variabel);
        var_dump($jsonfile);
    }
    public function set(string $key, $value,  bool $timpa = true): bool {
        // var_dump($this->database_variabel);
        if($timpa == false){
            if($this->database_variabel != null){
                if(isset($this->database_variabel[$key])){
                    throw new \Exception("Key $key sudah ada di database", 1);
                    return false;
                }else{
                    //cek jika config mau diload dari file
                    if($this->load_dari_file_for_set == true){
                        $this->database_variabel = json_decode(file_get_contents($this->filename), true);
                        if($this->database_variabel == null){
                            $this->database_variabel = dict[$key => $value];
                            return true;
                        }else{
                            if(isset($this->database_variabel[$key])){
                                throw new \Exception("Key $key sudah ada di database", 1);
                                return false;
                            }else{
                                $this->database_variabel[$key] = $value;
                                return true;
                            }
                        }
                        // if(isset($this->database_variabel[$key])){
                        //     throw new \Exception("Key $key sudah ada di database", 1);
                        //     return false;
                        // }else{
                        //     if($this->database_variabel == null){
                        //         $this->database_variabel = dict[$key => $value];;
                        //     }else{
                        //         $this->database_variabel[$key] = $value;
                        //     }
                        //     //$this->database_variabel[$key] = $value;
                        //     return true;
                        // }
                    }else{
                        $this->database_variabel[$key] = $value;
                        return true;
                    }
                    

                    // $this->database_variabel = dict[$key => $value];
                    
                    
                }
            }else{
                // if(isset($this->database_variabel[$key])){
                if($this->database_variabel == null){
                    if($this->load_dari_file_for_set == true){
                        $this->database_variabel = json_decode(file_get_contents($this->filename), true);
                        if($this->database_variabel == null){
                            $this->database_variabel = dict[$key => $value];
                            return true;
                        }else{
                            if(isset($this->database_variabel[$key])){
                                throw new \Exception("Key $key sudah ada di database", 1);
                                return false;
                            }else{
                                $this->database_variabel[$key] = $value;
                                return true;
                            }
                        }
                        
                    }else{
                        $this->database_variabel[$key] = $value;
                        return true;
                    }
                    // throw new \Exception("Key $key sudah ada di database", 1);
                }else{
                    // $this->database_variabel = dict[$key => $value];
                    if($this->database_variabel == null){
                        $this->database_variabel = dict[$key => $value];
                        return true;
                    }else{
                        $this->database_variabel[$key] = $value;
                        return true;
                    }
                    
                }
                // $this->database_variabel = dict[$key => $value];
                return true;
            }
            // if(isset($this->database_variabel[$key])){
            //     $ditemukan = true;
            // }
            // else{
            //     $this->database_variabel = json_decode(file_get_contents($this->filename), true);
            //     if(isset($this->database_variabel[$key])){
            //         $ditemukan = true;
            //     }else{
            //         $ditemukan = false;
            //     }
                
            // }
            // $check_jika_ada = ($ditemukan == true) ? true : false;

            // echo "debug timpa = 1";
            // if($check_jika_ada){
            //     throw new Exception("Key $key sudah ada di database", 1);
                    
            //     // }else{
            //     //     $this->database_variabel[$key] = $value;
            //     //     return true;
            //     //     echo "di db";
            //     // }
            // }else{
            //     // if(array_key_exists($key, $this->database_variabel)){
            //     //     print("Key $key sudah ada di database");
            //     // }else{
            //     //     $this->database_variabel[$key] = $value;
            //     //     return true;
            //     //     echo "di db";
            //     // }
            //     print("debug it");
            //     $this->database_variabel = dict[$key => $value];
            //     return true;
            // }
        }else{
            if($this->database_variabel != null){
                $this->database_variabel[$key] = $value;
                return true;
            }else{
                $this->database_variabel = dict[$key => $value];
                return true;
            }
        }
        
        // return false;
    }
    public function del($key): bool {
        // if(isset($this->database_variabel[$key])){
        //     unset($this->database_variabel[$key]);
        //     return true;
        // }else{
        //     throw new \Exception("Key $key tidak ada di database", 1);
        //     return false;
        // }
        if(isset($this->database_variabel[$key])){
            unset($this->database_variabel[$key]);
            return true;
        }
        else{

            $jsonfile  = json_decode(file_get_contents($this->filename), true);
            if(isset($jsonfile[$key])){
                unset($jsonfile[$key]);
                $this->jsonfile_arr = $jsonfile;
                if($jsonfile != null && $this->database_variabel != null){
                    $this->database_variabel = array_merge($jsonfile, $this->database_variabel);
                }elseif ($this->database_variabel == null) {
                    $this->database_variabel = $jsonfile;
                }elseif($jsonfile == null){
                    $this->database_variabel = $this->database_variabel;
                }
                return true;
            }else{
                return false;
            }
        }
    }

    public function get(string $key) {
        if(isset($this->database_variabel[$key])){
            return $this->database_variabel[$key];
        }
        else{
            $decode_filejson_nya = json_decode(file_get_contents($this->filename), true);
            if(isset($decode_filejson_nya[$key])){
                return $decode_filejson_nya[$key];
            }else{
                return null;
            }
        }
        // return $this->database_variabel[$key];
        
    }
    public function commit(){
        if(file_exists($this->filename)){
            $jsonfile = json_decode(file_get_contents($this->filename), true);

            if($jsonfile == $this->jsonfile_arr && $this->jsonfile_arr != null){
            // var_dump($jsonfile);
                if($jsonfile != null && $this->database_variabel != null){
                    $this->database_variabel = array_merge($jsonfile, $this->database_variabel);
                }elseif ($this->database_variabel == null) {
                    $this->database_variabel = $jsonfile;
                }elseif($jsonfile == null){
                    $this->database_variabel = $this->database_variabel;
                }

                file_put_contents($this->filename, json_encode($this->database_variabel));
            }elseif($this->jsonfile_arr == null){
                if($jsonfile != null && $this->database_variabel != null){
                    $this->database_variabel = array_merge($jsonfile, $this->database_variabel);
                }elseif ($this->database_variabel == null) {
                    $this->database_variabel = $jsonfile;
                }elseif($jsonfile == null){
                    $this->database_variabel = $this->database_variabel;
                }

                file_put_contents($this->filename, json_encode($this->database_variabel));
            }
            else{

                file_put_contents($this->filename, json_encode($this->database_variabel));
            }
            
        }else{
            // $this->database_variabel = array();
            // buat file
            file_put_contents($this->filename, json_encode($this->database_variabel));
        }
    }
}