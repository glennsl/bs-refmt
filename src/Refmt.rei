type ast;
type error = {.
  "message": string,
  "location": Js.nullable({.
    "startLine": int,
    "startLineStartChar": int,
    "endLine": int,
    "endLineEndChar": int
  })
};

let parseML  : string => Js.Result.t(ast, error);
let parseRE  : string => Js.Result.t(ast, error);
let parseREI : string => Js.Result.t(ast, error);
let printML  : ast => string;
let printRE  : ast => string;
let printREI : ast => string;