open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Caption";

let make =
  (
    ~style: option(BsReactNative.Style.t)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "style": from_opt(style)
      }
    ),
  children
);