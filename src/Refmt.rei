type ast;
type location = { line: int, column: int }
and  error = { message: string, from: location, until: location };

let parseML  : string => Belt.Result.t(ast, [> `RefmtParseError(error)]);
let parseMLI : string => Belt.Result.t(ast, [> `RefmtParseError(error)]);
let parseRE  : string => Belt.Result.t(ast, [> `RefmtParseError(error)]);
let parseREI : string => Belt.Result.t(ast, [> `RefmtParseError(error)]);
let printML  : ast => string;
let printMLI : ast => string;
let printRE  : ast => string;
let printREI : ast => string;
