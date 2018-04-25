[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ListItem";

let make =
    (
      ~title: option(ReasonReact.reactElement),
      ~description: option(ReasonReact.reactElement)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~avatar: option(ReasonReact.reactElement)=?,
      ~theme: option(Js.t({..}))=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "title": from_opt(title),
          "description": from_opt(description),
          "icon": from_opt(icon),
          "avatar": from_opt(avatar),
          "onPress": from_opt(onPress),
          "theme": from_opt(theme),
          "style": from_opt(style)
        }
      ),
    children
  );
