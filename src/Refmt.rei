type ast;
type location = { line: int, column: int }
and  error = { message: string, from: location, until: location };

let parseML  : string => Js.Result.t(ast, [> `RefmtParseError(error)]);
let parseRE  : string => Js.Result.t(ast, [> `RefmtParseError(error)]);
let parseREI : string => Js.Result.t(ast, [> `RefmtParseError(error)]);
let printML  : ast => string;
let printRE  : ast => string;
let printREI : ast => string;