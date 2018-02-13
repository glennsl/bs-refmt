# bs-refmt

Proof that Reason can consume OCaml by way of compiling to JavaScript. As a side-effect it also reformats things, without any need for IO monads&trade;, which shows conclusively that OCaml and Reason are superior to Haskell in every way. Q.E.D. &#x220e;

Or just BuckleScript bindings to [refmt.js](https://github.com/facebook/reason/#javascript-api)

## Installation

Run `npm install --save glennsl/bs-refmt` and add `bs-refmt` to the `bs-dependencies` in `bsconfig.json`. 

## Example

```reason
let ocamlCode  = {|
  let hello thing =
    Js.log {j|Hello $thing!|j}

  let () =
    hello "world"
|};

let reasonCode =
  ocamlCode |> Refmt.parseML
            |> fun | Ok(ast)  =>
                     ast |> Refmt.printRE |> Js.log

                   | Error(`RefmtParseError({ message })) =>
                     Js.log2("Error: ", message)
```

## Usage

### Bundling

The package has been tested to work with `webpack`, but requires a tiny bit of configuration because it depends on a few
ndoe modules in code paths that aren't actually used in practice. To stub these out, just put the following in your
`webpack.config.js`:

```javascript
  node: {
    fs: 'empty',
    child_process: 'empty'
  }
```
