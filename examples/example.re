let ocamlCode  = {|
  let hello thing =
    Js.log {j|Hello $thing!|j}

  let () =
    hello "world"
|};

let reasonCode =
  ocamlCode |> Refmt.parseML
            |> fun | Ok(ast)  => ast |> Refmt.printRE |> Js.log
                   | Error(e) => Js.log2("Error: ", e)
