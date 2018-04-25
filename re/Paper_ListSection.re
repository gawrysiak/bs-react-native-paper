[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ListSection";

let make =
    (
      ~title: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.({"title": from_opt(title), "theme": from_opt(theme)}),
    children
  );
