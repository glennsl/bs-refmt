type ast;

type  location = {
  line: int,
  column: int
}
and error = {
  message: string,
  from: location,
  until: location
};

type internalError = {.
  "message": string,
  "location": Js.nullable({.
    "startLine": int,
    "startLineStartChar": int,
    "endLine": int,
    "endLineEndChar": int
  })
};

external unsafeAsError : Js.Exn.t => internalError = "%identity";

let _wrap: ('a => 'b) => 'a => Js.Result.t('b, [> `RefmtParseError(error)]) = (f, x) =>
  try (Ok(f(x))) {
  | Js.Exn.Error(e) => {
      let err = unsafeAsError(e);

      Error(`RefmtParseError({
        message: err##message,
        from:
          switch (Js.Nullable.to_opt(err##location)) {
          | Some(l) => { line: l##startLine, column: l##startLineStartChar }
          | None    => { line: 0, column: 0 }
          },
        until:
          switch (Js.Nullable.to_opt(err##location)) {
          | Some(l) => { line: l##endLine, column: l##endLineEndChar }
          | None    => { line: 0, column: 0 }
          }
      }));
    }
  };

[@bs.val] [@bs.module "reason"] external parseML : string => ast = "";
[@bs.val] [@bs.module "reason"] external parseRE : string => ast = "";
[@bs.val] [@bs.module "reason"] external parseREI : string => ast = "";
[@bs.val] [@bs.module "reason"] external printML : ast => string = "";
[@bs.val] [@bs.module "reason"] external printRE : ast => string = "";
[@bs.val] [@bs.module "reason"] external printREI : ast => string = "";

let parseML = _wrap(parseML);
let parseRE = _wrap(parseRE);
let parseREI = _wrap(parseREI);