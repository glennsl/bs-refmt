
let ocamlCode  = {|
  let x =
    match 42 with 
    | .1 -> 4
    | _ -> 2
|};

let reasonCode =
  ocamlCode |> Refmt.parseML
            |> fun | Ok(_)  =>
                     failwith("unreachable")

                   | Error(`RefmtParseError({ message })) =>
                     Js.log2("Error: ", message)
