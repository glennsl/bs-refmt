// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Refmt = require("../src/Refmt.bs.js");

var ocamlCode = "\n  let hello thing =\n    Js.log {j|Hello $thing!|j}\n\n  let () =\n    hello \"world\"\n";

var param = Refmt.parseML(ocamlCode);

var reasonCode;

if (param.tag) {
  console.log("Error: ", param[0][1][/* message */0]);
  reasonCode = /* () */0;
} else {
  console.log(Refmt.printRE(param[0]));
  reasonCode = /* () */0;
}

exports.ocamlCode = ocamlCode;
exports.reasonCode = reasonCode;
/* param Not a pure module */
