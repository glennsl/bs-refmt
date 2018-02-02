# bs-refmt

Proof that Reason can consume OCaml by way of compiling to JavaScript. As a side-effect it also reformats things, without any need for IO monads&trade;, which shows conclusively that OCaml and Reason are superior to Haskell in every way. Q.E.D. &#x220e;

Or just BuckleScript bindings to [refmt.js](https://github.com/facebook/reason/#javascript-api)

## Installation

Run `npm install --save glennsl/bs-refmt` and add `bs-refmt` to the `bs-dependencies` in `bsconfig.json`. 

## Example

```reason
[@bs.val] external eval : string => 'a = "";

let ocamlCode  = {|
  let hello thing =
    Js.log {j|Hello $thing!|j}

  let () =
    hello "world"
|};

let reasonCode =
  ocamlCode |> Refmt.parseML
            |> Refmt.printRE;
```