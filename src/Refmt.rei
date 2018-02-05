type ast
and  location = { line: int, column: int }
and  error = { message: string, from: location, until: location }
and  result = Js.Result.t(ast, error);

let parseML  : string => Js.Result.t(ast, error);
let parseRE  : string => Js.Result.t(ast, error);
let parseREI : string => Js.Result.t(ast, error);
let printML  : ast => string;
let printRE  : ast => string;
let printREI : ast => string;