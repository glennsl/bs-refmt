
let ocamlCode  = {|
  let x =
    switch 42 {
    | .1 => 4
    | _ => 2
    }
|};

let reasonCode =
  ocamlCode |> Refmt.parseRE
            |> fun | Ok(_)  => failwith("unreachable")
                   | Error(e) => Js.log2("Error: ", e##message)