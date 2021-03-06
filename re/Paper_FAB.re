[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "FAB";

let make =
    (
      ~small: bool=false,
      ~dark: bool=false,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~icon: ReasonReact.reactElement,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "small": Js.Boolean.to_js_boolean(small),
          "dark": Js.Boolean.to_js_boolean(dark),
          "color": from_opt(color),
          "icon": icon,
          "onPress": from_opt(onPress),
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
