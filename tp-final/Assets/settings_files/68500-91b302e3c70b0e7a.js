"use strict";(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[68500],{524299:function(e,t,o){o.d(t,{U:function(){return d}});var n=o(41732),a=o(535630),r=o(470079),l=o(507487),i=o(429867),c=o(186799),s=o(85688);function d(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},t=e.disabled,o=void 0!==t&&t,d=e.focusableWhenDisabled,u=e.href,m=e.rootRef,v=e.tabIndex,h=e.to,f=e.type,p=e.rootElementName,g=r.useRef(),y=r.useState(!1),S=(0,a.Z)(y,2),C=S[0],b=S[1],x=(0,l.Z)(),Z=x.isFocusVisibleRef,k=x.onFocus,F=x.onBlur,B=x.ref,w=r.useState(!1),D=(0,a.Z)(w,2),H=D[0],E=D[1];o&&!d&&H&&E(!1),r.useEffect(function(){Z.current=H},[H,Z]);var A=(0,s.F)({rootElementName:null!=p?p:u||h?"a":void 0,componentName:"Button"}),I=(0,a.Z)(A,2),z=I[0],M=I[1],W=function(){var e=g.current;return"BUTTON"===z||"INPUT"===z&&["button","submit","reset"].includes(null==e?void 0:e.type)||"A"===z&&(null==e?void 0:e.href)},V=(0,i.Z)(M,m,B,g),j={};return void 0!==v&&(j.tabIndex=v),"BUTTON"===z?(j.type=null!=f?f:"button",d?j["aria-disabled"]=o:j.disabled=o):"INPUT"===z?f&&["button","submit","reset"].includes(f)&&(d?j["aria-disabled"]=o:j.disabled=o):""!==z&&(u||h||(j.role="button",j.tabIndex=null!=v?v:0),o&&(j["aria-disabled"]=o,j.tabIndex=d?null!=v?v:0:-1)),{getRootProps:function(){var t=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},a=(0,n.Z)((0,n.Z)({},(0,c._)(e)),(0,c._)(t)),r=(0,n.Z)((0,n.Z)((0,n.Z)((0,n.Z)({type:f},a),j),t),{},{onBlur:function(e){var t;F(e),!1===Z.current&&E(!1),null===(t=a.onBlur)||void 0===t||t.call(a,e)},onClick:function(e){if(!o){var t;null===(t=a.onClick)||void 0===t||t.call(a,e)}},onFocus:function(e){var t,o;g.current||(g.current=e.currentTarget),k(e),!0===Z.current&&(E(!0),null===(o=a.onFocusVisible)||void 0===o||o.call(a,e)),null===(t=a.onFocus)||void 0===t||t.call(a,e)},onKeyDown:function(e){var t,n;null===(t=a.onKeyDown)||void 0===t||t.call(a,e),!e.defaultMuiPrevented&&(e.target!==e.currentTarget||W()||" "!==e.key||e.preventDefault(),e.target!==e.currentTarget||" "!==e.key||o||b(!0),e.target!==e.currentTarget||W()||"Enter"!==e.key||o||(null===(n=a.onClick)||void 0===n||n.call(a,e),e.preventDefault()))},onKeyUp:function(e){var t,n;e.target===e.currentTarget&&b(!1),null===(t=a.onKeyUp)||void 0===t||t.call(a,e),e.target!==e.currentTarget||W()||o||" "!==e.key||e.defaultMuiPrevented||null===(n=a.onClick)||void 0===n||n.call(a,e)},onMouseDown:function(e){var t;o||(b(!0),document.addEventListener("mouseup",function(){b(!1)},{once:!0})),null===(t=a.onMouseDown)||void 0===t||t.call(a,e)},onMouseLeave:function(e){var t;H&&e.preventDefault(),null===(t=a.onMouseLeave)||void 0===t||t.call(a,e)},ref:V});return delete r.onFocusVisible,r},focusVisible:H,setFocusVisible:E,active:C,rootRef:V}}},85688:function(e,t,o){o.d(t,{F:function(){return r}});var n=o(535630),a=o(470079);function r(e){var t=e.rootElementName;e.componentName;var o=a.useState((void 0===t?"":t).toUpperCase()),r=(0,n.Z)(o,2),l=r[0],i=r[1];return[l,a.useCallback(function(e){var t;i(null!==(t=null==e?void 0:e.tagName)&&void 0!==t?t:"")},[])]}},437501:function(e,t,o){o.d(t,{d6:function(){return r},sI:function(){return l}});var n=o(743064),a=o(983433),r=function(e,t){return(0,n.ZP)(e,t,"Mui")},l=function(e,t){return(0,a.Z)(e,t,"Mui")}},958901:function(e,t){t.Z={grey:{50:"#FBFCFE",100:"#F0F4F8",200:"#DDE7EE",300:"#CDD7E1",400:"#9FA6AD",500:"#636B74",600:"#555E68",700:"#32383E",800:"#171A1C",900:"#0B0D0E"},blue:{50:"#EDF5FD",100:"#E3EFFB",200:"#C7DFF7",300:"#97C3F0",400:"#4393E4",500:"#0B6BCB",600:"#185EA5",700:"#12467B",800:"#0A2744",900:"#051423"},yellow:{50:"#FEFAF6",100:"#FDF0E1",200:"#FCE1C2",300:"#F3C896",400:"#EA9A3E",500:"#9A5B13",600:"#72430D",700:"#492B08",800:"#2E1B05",900:"#1D1002"},red:{50:"#FEF6F6",100:"#FCE4E4",200:"#F7C5C5",300:"#F09898",400:"#E47474",500:"#C41C1C",600:"#A51818",700:"#7D1212",800:"#430A0A",900:"#240505"},green:{50:"#F6FEF6",100:"#E3FBE3",200:"#C7F7C7",300:"#A1E8A1",400:"#51BC51",500:"#1F7A1F",600:"#136C13",700:"#0A470A",800:"#042F04",900:"#021D02"}}},912526:function(e,t,o){o.d(t,{JO:function(){return s},lL:function(){return i},tv:function(){return c}});var n=o(975518),a=o(762443),r=o(284332),l=(0,n.Z)({themeId:r.Z,theme:a.Z,attribute:"data-joy-color-scheme",modeStorageKey:"joy-mode",colorSchemeStorageKey:"joy-color-scheme",defaultColorScheme:{light:"light",dark:"dark"}}),i=l.CssVarsProvider,c=l.useColorScheme,s=l.getInitColorSchemeScript},762443:function(e,t,o){var n=(0,o(794849).Z)();t.Z=n},794849:function(e,t,o){o.d(t,{N:function(){return H},Z:function(){return E}});var n=o(535630),a=o(41732),r=o(532534),l=o(512815),i=o.n(l),c=o(456765),s=o.n(c),d=o(357814),u=o(793975),m=o(511550),v=o(815615),h=o(29193),f=o(371340),p=o(296106),g=o(871029),y=o(533347),S=(0,a.Z)((0,a.Z)({},y.Z),{},{borderRadius:{themeKey:"radius"},boxShadow:{themeKey:"shadow"},fontFamily:{themeKey:"fontFamily"},fontSize:{themeKey:"fontSize"},fontWeight:{themeKey:"fontWeight"},letterSpacing:{themeKey:"letterSpacing"},lineHeight:{themeKey:"lineHeight"}}),C=o(958901),b=o(403749),x=o(437501),Z=o(974468),k=function(e,t,o){t.includes("Color")&&(e.color=o),t.includes("Bg")&&(e.backgroundColor=o),t.includes("Border")&&(e.borderColor=o)},F=function(e,t,o){var a={};return s()(t||{}).forEach(function(t){var r=(0,n.Z)(t,2),l=r[0],i=r[1];if(l.match(RegExp("".concat(e,"(color|bg|border)"),"i"))&&i){var c=o?o(l):i;l.includes("Disabled")&&(a.pointerEvents="none",a.cursor="default",a["--Icon-color"]="currentColor"),l.match(/(Hover|Active|Disabled)/)||(a["--variant-borderWidth"]||(a["--variant-borderWidth"]="0px"),l.includes("Border")&&(a["--variant-borderWidth"]="1px",a.border="var(--variant-borderWidth) solid")),k(a,l,c)}}),a},B=function(e,t){var o={};if(t){var r=t.getCssVar,l=t.palette;s()(l).forEach(function(t){var c=(0,n.Z)(t,2),s=c[0],d=c[1];d&&"object"==typeof d&&i()(d).some(function(e){var t;return null===(t=e.match)||void 0===t?void 0:t.call(e,/^(plain(Hover|Active|Disabled)?(Color|Bg)|outlined(Hover|Active|Disabled)?(Color|Border|Bg)|soft(Hover|Active|Disabled)?(Color|Bg)|solid(Hover|Active|Disabled)?(Color|Bg))$/)})&&"object"==typeof d&&(o=(0,a.Z)((0,a.Z)({},o),{},(0,Z.Z)({},s,F(e,d,function(e){return"var(--variant-".concat(e,", ").concat(r("palette-".concat(s,"-").concat(e),l[s][e]),")")}))))})}return o.context=F(e,{plainColor:"var(--variant-plainColor)",plainHoverColor:"var(--variant-plainHoverColor)",plainHoverBg:"var(--variant-plainHoverBg)",plainActiveBg:"var(--variant-plainActiveBg)",plainDisabledColor:"var(--variant-plainDisabledColor)",outlinedColor:"var(--variant-outlinedColor)",outlinedBorder:"var(--variant-outlinedBorder)",outlinedHoverColor:"var(--variant-outlinedHoverColor)",outlinedHoverBorder:"var(--variant-outlinedHoverBorder)",outlinedHoverBg:"var(--variant-outlinedHoverBg)",outlinedActiveBg:"var(--variant-outlinedActiveBg)",outlinedDisabledColor:"var(--variant-outlinedDisabledColor)",outlinedDisabledBorder:"var(--variant-outlinedDisabledBorder)",softColor:"var(--variant-softColor)",softBg:"var(--variant-softBg)",softHoverColor:"var(--variant-softHoverColor)",softHoverBg:"var(--variant-softHoverBg)",softActiveBg:"var(--variant-softActiveBg)",softDisabledColor:"var(--variant-softDisabledColor)",softDisabledBg:"var(--variant-softDisabledBg)",solidColor:"var(--variant-solidColor)",solidBg:"var(--variant-solidBg)",solidHoverBg:"var(--variant-solidHoverBg)",solidActiveBg:"var(--variant-solidActiveBg)",solidDisabledColor:"var(--variant-solidDisabledColor)",solidDisabledBg:"var(--variant-solidDisabledBg)"}),o},w=["cssVarPrefix","breakpoints","spacing","components","variants","shouldSkipGeneratingVar"],D=["colorSchemes"],H=function(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:"joy";return(0,u.Z)(e)};function E(e){var t,o,l,c,u,y,Z,k,F,E,A,I,z,M=e||{},W=M.cssVarPrefix,V=void 0===W?"joy":W,j=M.breakpoints,K=M.spacing,P=M.components,O=M.variants,R=M.shouldSkipGeneratingVar,N=void 0===R?b.Z:R,T=(0,r.Z)(M,w),L=H(V),U={primary:C.Z.blue,neutral:C.Z.grey,danger:C.Z.red,success:C.Z.green,warning:C.Z.yellow,common:{white:"#FFF",black:"#000"}},_=function(e){var t,o=e.split("-"),n=o[1],a=o[2];return L(e,null===(t=U[n])||void 0===t?void 0:t[a])},$=function(e){return{plainColor:_("palette-".concat(e,"-500")),plainHoverBg:_("palette-".concat(e,"-100")),plainActiveBg:_("palette-".concat(e,"-200")),plainDisabledColor:_("palette-neutral-400"),outlinedColor:_("palette-".concat(e,"-500")),outlinedBorder:_("palette-".concat(e,"-300")),outlinedHoverBg:_("palette-".concat(e,"-100")),outlinedActiveBg:_("palette-".concat(e,"-200")),outlinedDisabledColor:_("palette-neutral-400"),outlinedDisabledBorder:_("palette-neutral-200"),softColor:_("palette-".concat(e,"-700")),softBg:_("palette-".concat(e,"-100")),softHoverBg:_("palette-".concat(e,"-200")),softActiveColor:_("palette-".concat(e,"-800")),softActiveBg:_("palette-".concat(e,"-300")),softDisabledColor:_("palette-neutral-400"),softDisabledBg:_("palette-neutral-50"),solidColor:_("palette-common-white"),solidBg:_("palette-".concat(e,"-500")),solidHoverBg:_("palette-".concat(e,"-600")),solidActiveBg:_("palette-".concat(e,"-700")),solidDisabledColor:_("palette-neutral-400"),solidDisabledBg:_("palette-neutral-100")}},G=function(e){return{plainColor:_("palette-".concat(e,"-300")),plainHoverBg:_("palette-".concat(e,"-800")),plainActiveBg:_("palette-".concat(e,"-700")),plainDisabledColor:_("palette-neutral-500"),outlinedColor:_("palette-".concat(e,"-200")),outlinedBorder:_("palette-".concat(e,"-700")),outlinedHoverBg:_("palette-".concat(e,"-800")),outlinedActiveBg:_("palette-".concat(e,"-700")),outlinedDisabledColor:_("palette-neutral-500"),outlinedDisabledBorder:_("palette-neutral-800"),softColor:_("palette-".concat(e,"-200")),softBg:_("palette-".concat(e,"-800")),softHoverBg:_("palette-".concat(e,"-700")),softActiveColor:_("palette-".concat(e,"-100")),softActiveBg:_("palette-".concat(e,"-600")),softDisabledColor:_("palette-neutral-500"),softDisabledBg:_("palette-neutral-800"),solidColor:_("palette-common-white"),solidBg:_("palette-".concat(e,"-500")),solidHoverBg:_("palette-".concat(e,"-600")),solidActiveBg:_("palette-".concat(e,"-700")),solidDisabledColor:_("palette-neutral-500"),solidDisabledBg:_("palette-neutral-800")}},q={palette:{mode:"light",primary:(0,a.Z)((0,a.Z)({},U.primary),$("primary")),neutral:(0,a.Z)((0,a.Z)((0,a.Z)({},U.neutral),$("neutral")),{},{plainColor:_("palette-neutral-700"),plainHoverColor:_("palette-neutral-900"),outlinedColor:_("palette-neutral-700")}),danger:(0,a.Z)((0,a.Z)({},U.danger),$("danger")),success:(0,a.Z)((0,a.Z)({},U.success),$("success")),warning:(0,a.Z)((0,a.Z)({},U.warning),$("warning")),common:{white:"#FFF",black:"#000"},text:{primary:_("palette-neutral-800"),secondary:_("palette-neutral-700"),tertiary:_("palette-neutral-600"),icon:_("palette-neutral-500")},background:{body:_("palette-common-white"),surface:_("palette-neutral-50"),popup:_("palette-common-white"),level1:_("palette-neutral-100"),level2:_("palette-neutral-200"),level3:_("palette-neutral-300"),tooltip:_("palette-neutral-500"),backdrop:"rgba(".concat(L("palette-neutral-darkChannel",(0,m.n8)(U.neutral[900]))," / 0.25)")},divider:"rgba(".concat(L("palette-neutral-mainChannel",(0,m.n8)(U.neutral[500]))," / 0.2)"),focusVisible:_("palette-primary-500")},shadowRing:"0 0 #000",shadowChannel:"21 21 21",shadowOpacity:"0.08"},J={palette:{mode:"dark",primary:(0,a.Z)((0,a.Z)({},U.primary),G("primary")),neutral:(0,a.Z)((0,a.Z)((0,a.Z)({},U.neutral),G("neutral")),{},{plainColor:_("palette-neutral-300"),plainHoverColor:_("palette-neutral-300")}),danger:(0,a.Z)((0,a.Z)({},U.danger),G("danger")),success:(0,a.Z)((0,a.Z)({},U.success),G("success")),warning:(0,a.Z)((0,a.Z)({},U.warning),G("warning")),common:{white:"#FFF",black:"#000"},text:{primary:_("palette-neutral-100"),secondary:_("palette-neutral-300"),tertiary:_("palette-neutral-400"),icon:_("palette-neutral-400")},background:{body:_("palette-common-black"),surface:_("palette-neutral-900"),popup:_("palette-common-black"),level1:_("palette-neutral-800"),level2:_("palette-neutral-700"),level3:_("palette-neutral-600"),tooltip:_("palette-neutral-600"),backdrop:"rgba(".concat(L("palette-neutral-darkChannel",(0,m.n8)(U.neutral[50]))," / 0.25)")},divider:"rgba(".concat(L("palette-neutral-mainChannel",(0,m.n8)(U.neutral[500]))," / 0.16)"),focusVisible:_("palette-primary-500")},shadowRing:"0 0 #000",shadowChannel:"0 0 0",shadowOpacity:"0.6"},Q='-apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol"',X=(0,a.Z)({body:'"Inter", '.concat(L("fontFamily-fallback, ".concat(Q))),display:'"Inter", '.concat(L("fontFamily-fallback, ".concat(Q))),code:"Source Code Pro,ui-monospace,SFMono-Regular,Menlo,Monaco,Consolas,Liberation Mono,Courier New,monospace",fallback:Q},T.fontFamily),Y=(0,a.Z)({sm:300,md:500,lg:600,xl:700},T.fontWeight),ee=(0,a.Z)({xs:"0.75rem",sm:"0.875rem",md:"1rem",lg:"1.125rem",xl:"1.25rem",xl2:"1.5rem",xl3:"1.875rem",xl4:"2.25rem"},T.fontSize),et=(0,a.Z)({xs:"1.33334",sm:"1.42858",md:"1.5",lg:"1.55556",xl:"1.66667"},T.lineHeight),eo=null!==(t=null===(o=T.colorSchemes)||void 0===o?void 0:null===(l=o.light)||void 0===l?void 0:l.shadowRing)&&void 0!==t?t:q.shadowRing,en=null!==(c=null===(u=T.colorSchemes)||void 0===u?void 0:null===(y=u.light)||void 0===y?void 0:y.shadowChannel)&&void 0!==c?c:q.shadowChannel,ea=null!==(Z=null===(k=T.colorSchemes)||void 0===k?void 0:null===(F=k.light)||void 0===F?void 0:F.shadowOpacity)&&void 0!==Z?Z:q.shadowOpacity,er={colorSchemes:{light:q,dark:J},fontSize:ee,fontFamily:X,fontWeight:Y,focus:{thickness:"2px",selector:"&.".concat((0,x.d6)("","focusVisible"),", &:focus-visible"),default:{outlineOffset:"var(--focus-outline-offset, ".concat(L("focus-thickness",null!==(E=null===(A=T.focus)||void 0===A?void 0:A.thickness)&&void 0!==E?E:"2px"),")"),outline:"".concat(L("focus-thickness",null!==(I=null===(z=T.focus)||void 0===z?void 0:z.thickness)&&void 0!==I?I:"2px")," solid ").concat(L("palette-focusVisible",U.primary[500]))}},lineHeight:et,radius:{xs:"2px",sm:"6px",md:"8px",lg:"12px",xl:"16px"},shadow:{xs:"".concat(L("shadowRing",eo),", 0px 1px 2px 0px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),")"),sm:"".concat(L("shadowRing",eo),", 0px 1px 2px 0px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),"), 0px 2px 4px 0px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),")"),md:"".concat(L("shadowRing",eo),", 0px 2px 8px -2px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),"), 0px 6px 12px -2px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),")"),lg:"".concat(L("shadowRing",eo),", 0px 2px 8px -2px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),"), 0px 12px 16px -4px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),")"),xl:"".concat(L("shadowRing",eo),", 0px 2px 8px -2px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),"), 0px 20px 24px -4px rgba(").concat(L("shadowChannel",en)," / ").concat(L("shadowOpacity",ea),")")},zIndex:{badge:1,table:10,popup:1e3,modal:1300,snackbar:1400,tooltip:1500},typography:{h1:{fontFamily:L("fontFamily-display, ".concat(X.display)),fontWeight:L("fontWeight-xl, ".concat(Y.xl)),fontSize:L("fontSize-xl4, ".concat(ee.xl4)),lineHeight:L("lineHeight-xs, ".concat(et.xs)),letterSpacing:"-0.025em",color:L("palette-text-primary, ".concat(q.palette.text.primary))},h2:{fontFamily:L("fontFamily-display, ".concat(X.display)),fontWeight:L("fontWeight-xl, ".concat(Y.xl)),fontSize:L("fontSize-xl3, ".concat(ee.xl3)),lineHeight:L("lineHeight-xs, ".concat(et.xs)),letterSpacing:"-0.025em",color:L("palette-text-primary, ".concat(q.palette.text.primary))},h3:{fontFamily:L("fontFamily-display, ".concat(X.display)),fontWeight:L("fontWeight-lg, ".concat(Y.lg)),fontSize:L("fontSize-xl2, ".concat(ee.xl2)),lineHeight:L("lineHeight-xs, ".concat(et.xs)),letterSpacing:"-0.025em",color:L("palette-text-primary, ".concat(q.palette.text.primary))},h4:{fontFamily:L("fontFamily-display, ".concat(X.display)),fontWeight:L("fontWeight-lg, ".concat(Y.lg)),fontSize:L("fontSize-xl, ".concat(ee.xl)),lineHeight:L("lineHeight-md, ".concat(et.md)),letterSpacing:"-0.025em",color:L("palette-text-primary, ".concat(q.palette.text.primary))},"title-lg":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontWeight:L("fontWeight-lg, ".concat(Y.lg)),fontSize:L("fontSize-lg, ".concat(ee.lg)),lineHeight:L("lineHeight-xs, ".concat(et.xs)),color:L("palette-text-primary, ".concat(q.palette.text.primary))},"title-md":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontWeight:L("fontWeight-md, ".concat(Y.md)),fontSize:L("fontSize-md, ".concat(ee.md)),lineHeight:L("lineHeight-md, ".concat(et.md)),color:L("palette-text-primary, ".concat(q.palette.text.primary))},"title-sm":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontWeight:L("fontWeight-md, ".concat(Y.md)),fontSize:L("fontSize-sm, ".concat(ee.sm)),lineHeight:L("lineHeight-sm, ".concat(et.sm)),color:L("palette-text-primary, ".concat(q.palette.text.primary))},"body-lg":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontSize:L("fontSize-lg, ".concat(ee.lg)),lineHeight:L("lineHeight-md, ".concat(et.md)),color:L("palette-text-secondary, ".concat(q.palette.text.secondary))},"body-md":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontSize:L("fontSize-md, ".concat(ee.md)),lineHeight:L("lineHeight-md, ".concat(et.md)),color:L("palette-text-secondary, ".concat(q.palette.text.secondary))},"body-sm":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontSize:L("fontSize-sm, ".concat(ee.sm)),lineHeight:L("lineHeight-md, ".concat(et.md)),color:L("palette-text-tertiary, ".concat(q.palette.text.tertiary))},"body-xs":{fontFamily:L("fontFamily-body, ".concat(X.body)),fontWeight:L("fontWeight-md, ".concat(Y.md)),fontSize:L("fontSize-xs, ".concat(ee.xs)),lineHeight:L("lineHeight-md, ".concat(et.md)),color:L("palette-text-tertiary, ".concat(q.palette.text.tertiary))}}},el=T?(0,d.Z)(er,T):er,ei=el.colorSchemes,ec=(0,r.Z)(el,D),es=(0,a.Z)((0,a.Z)({colorSchemes:ei},ec),{},{breakpoints:(0,v.Z)(null!=j?j:{}),components:(0,d.Z)({MuiSvgIcon:{defaultProps:{fontSize:"xl2"},styleOverrides:{root:function(e){var t,o=e.ownerState,n=e.theme,r=o.instanceFontSize;return(0,a.Z)((0,a.Z)((0,a.Z)({margin:"var(--Icon-margin)"},o.fontSize&&"inherit"!==o.fontSize&&{fontSize:"var(--Icon-fontSize, ".concat(n.vars.fontSize[o.fontSize],")")}),!o.htmlColor&&(0,a.Z)({color:"var(--Icon-color, ".concat(es.vars.palette.text.icon,")")},o.color&&"inherit"!==o.color&&n.vars.palette[o.color]&&{color:"rgba(".concat(null===(t=n.vars.palette[o.color])||void 0===t?void 0:t.mainChannel," / 1)")})),r&&"inherit"!==r&&{"--Icon-fontSize":n.vars.fontSize[r]})}}}},P),cssVarPrefix:V,getCssVar:L,spacing:(0,h.Z)(K)});s()(es.colorSchemes).forEach(function(e){var t=(0,n.Z)(e,2);!function(e,t){i()(t).forEach(function(o){var n={main:"500",light:"200",dark:"700"};"dark"===e&&(n.main=400),!t[o].mainChannel&&t[o][n.main]&&(t[o].mainChannel=(0,m.n8)(t[o][n.main])),!t[o].lightChannel&&t[o][n.light]&&(t[o].lightChannel=(0,m.n8)(t[o][n.light])),!t[o].darkChannel&&t[o][n.dark]&&(t[o].darkChannel=(0,m.n8)(t[o][n.dark]))})}(t[0],t[1].palette)});var ed=(0,f.Z)((0,a.Z)({colorSchemes:ei},ec),{prefix:V,shouldSkipGeneratingVar:N}),eu=ed.vars,em=ed.generateCssVars;es.vars=eu,es.generateCssVars=em,es.unstable_sxConfig=(0,a.Z)((0,a.Z)({},S),null==e?void 0:e.unstable_sxConfig),es.unstable_sx=function(e){return(0,p.Z)({sx:e,theme:this})},es.getColorSchemeSelector=function(e){return"light"===e?"&":'&[data-joy-color-scheme="'.concat(e,'"], [data-joy-color-scheme="').concat(e,'"] &')};var ev={getCssVar:L,palette:es.colorSchemes.light.palette};return es.variants=(0,d.Z)({plain:B("plain",ev),plainHover:B("plainHover",ev),plainActive:B("plainActive",ev),plainDisabled:B("plainDisabled",ev),outlined:B("outlined",ev),outlinedHover:B("outlinedHover",ev),outlinedActive:B("outlinedActive",ev),outlinedDisabled:B("outlinedDisabled",ev),soft:B("soft",ev),softHover:B("softHover",ev),softActive:B("softActive",ev),softDisabled:B("softDisabled",ev),solid:B("solid",ev),solidHover:B("solidHover",ev),solidActive:B("solidActive",ev),solidDisabled:B("solidDisabled",ev)},O),es.palette=(0,a.Z)((0,a.Z)({},es.colorSchemes.light.palette),{},{colorScheme:"light"}),es.shouldSkipGeneratingVar=N,es.applyStyles=g.Z,es}},284332:function(e,t){t.Z="$$joy"},403749:function(e,t,o){o.d(t,{Z:function(){return n}});function n(e){var t;return!!e[0].match(/^(typography|variants|breakpoints)$/)||!!e[0].match(/sxConfig$/)||"palette"===e[0]&&!!(null!==(t=e[1])&&void 0!==t&&t.match(/^(mode)$/))||"focus"===e[0]&&"thickness"!==e[1]}},498657:function(e,t,o){var n=o(614260),a=o(762443),r=o(284332),l=(0,n.ZP)({defaultTheme:a.Z,themeId:r.Z});t.Z=l},975518:function(e,t,o){o.d(t,{Z:function(){return F}});var n=o(974468),a=o(535630),r=o(41732),l=o(532534),i=o(639398),c=o(512815),s=o.n(c),d=o(456765),u=o.n(d),m=o(470079),v=o(357814),h=o(940718),f=o(674416),p=o(276220),g=o(735250),y="mode",S="color-scheme",C="data-color-scheme";function b(e){if("system"===e)return window.matchMedia("(prefers-color-scheme: dark)").matches?"dark":"light"}function x(e,t){return"light"===e.mode||"system"===e.mode&&"light"===e.systemMode?t("light"):"dark"===e.mode||"system"===e.mode&&"dark"===e.systemMode?t("dark"):void 0}function Z(e,t){var o;try{(o=localStorage.getItem(e)||void 0)||localStorage.setItem(e,t)}catch(e){}return o||t}var k=["colorSchemes","components","generateCssVars","cssVarPrefix"];function F(e){var t=e.themeId,o=e.theme,c=void 0===o?{}:o,d=e.attribute,F=void 0===d?C:d,B=e.modeStorageKey,w=void 0===B?y:B,D=e.colorSchemeStorageKey,H=void 0===D?S:D,E=e.defaultMode,A=void 0===E?"light":E,I=e.defaultColorScheme,z=e.disableTransitionOnChange,M=void 0!==z&&z,W=e.resolveTheme,V=e.excludeVariablesFromRoot;c.colorSchemes&&("string"!=typeof I||c.colorSchemes[I])&&("object"!=typeof I||c.colorSchemes[null==I?void 0:I.light])&&("object"!=typeof I||c.colorSchemes[null==I?void 0:I.dark])||console.error("MUI: `".concat(I,"` does not exist in `theme.colorSchemes`."));var j=m.createContext(void 0),K="string"==typeof I?I:I.light,P="string"==typeof I?I:I.dark;return{CssVarsProvider:function(e){var o,i,d,C,B,D,E,z,K,P,O,R,N,T,L,U,_,$,G,q,J,Q,X=e.children,Y=e.theme,ee=void 0===Y?c:Y,et=e.modeStorageKey,eo=e.colorSchemeStorageKey,en=e.attribute,ea=void 0===en?F:en,er=e.defaultMode,el=void 0===er?A:er,ei=e.defaultColorScheme,ec=void 0===ei?I:ei,es=e.disableTransitionOnChange,ed=void 0===es?M:es,eu=e.storageWindow,em=void 0===eu?window:eu,ev=e.documentNode,eh=void 0===ev?"undefined"==typeof document?void 0:document:ev,ef=e.colorSchemeNode,ep=void 0===ef?"undefined"==typeof document?void 0:document.documentElement:ef,eg=e.colorSchemeSelector,ey=void 0===eg?":root":eg,eS=e.disableNestedContext,eC=e.disableStyleSheetGeneration,eb=m.useRef(!1),ex=(0,f.Z)(),eZ=m.useContext(j),ek=!!eZ&&!(void 0!==eS&&eS),eF=ee[t],eB=eF||ee,ew=eB.colorSchemes,eD=void 0===ew?{}:ew,eH=eB.components,eE=eB.generateCssVars,eA=void 0===eE?function(){return{vars:{},css:{}}}:eE,eI=eB.cssVarPrefix,ez=(0,l.Z)(eB,k),eM=s()(eD),eW="string"==typeof ec?ec:ec.light,eV="string"==typeof ec?ec:ec.dark,ej=(d=void 0===(i=(o={supportedColorSchemes:eM,defaultLightColorScheme:eW,defaultDarkColorScheme:eV,modeStorageKey:void 0===et?w:et,colorSchemeStorageKey:void 0===eo?H:eo,defaultMode:el,storageWindow:em}).defaultMode)?"light":i,C=o.defaultLightColorScheme,B=o.defaultDarkColorScheme,D=o.supportedColorSchemes,z=void 0===(E=o.modeStorageKey)?y:E,P=void 0===(K=o.colorSchemeStorageKey)?S:K,R=void 0===(O=o.storageWindow)?window:O,N=(void 0===D?[]:D).join(","),T=m.useState(function(){var e=Z(z,d),t=Z("".concat(P,"-light"),C),o=Z("".concat(P,"-dark"),B);return{mode:e,systemMode:b(e),lightColorScheme:t,darkColorScheme:o}}),U=(L=(0,a.Z)(T,2))[0],_=L[1],$=x(U,function(e){return"light"===e?U.lightColorScheme:"dark"===e?U.darkColorScheme:void 0}),G=m.useCallback(function(e){_(function(t){if(e===t.mode)return t;var o=null!=e?e:d;try{localStorage.setItem(z,o)}catch(e){}return(0,r.Z)((0,r.Z)({},t),{},{mode:o,systemMode:b(o)})})},[z,d]),q=m.useCallback(function(e){e?"string"==typeof e?e&&!N.includes(e)?console.error("`".concat(e,"` does not exist in `theme.colorSchemes`.")):_(function(t){var o=(0,r.Z)({},t);return x(t,function(t){try{localStorage.setItem("".concat(P,"-").concat(t),e)}catch(e){}"light"===t&&(o.lightColorScheme=e),"dark"===t&&(o.darkColorScheme=e)}),o}):_(function(t){var o=(0,r.Z)({},t),n=null===e.light?C:e.light,a=null===e.dark?B:e.dark;if(n){if(N.includes(n)){o.lightColorScheme=n;try{localStorage.setItem("".concat(P,"-light"),n)}catch(e){}}else console.error("`".concat(n,"` does not exist in `theme.colorSchemes`."))}if(a){if(N.includes(a)){o.darkColorScheme=a;try{localStorage.setItem("".concat(P,"-dark"),a)}catch(e){}}else console.error("`".concat(a,"` does not exist in `theme.colorSchemes`."))}return o}):_(function(e){try{localStorage.setItem("".concat(P,"-light"),C),localStorage.setItem("".concat(P,"-dark"),B)}catch(e){}return(0,r.Z)((0,r.Z)({},e),{},{lightColorScheme:C,darkColorScheme:B})})},[N,P,C,B]),J=m.useCallback(function(e){"system"===U.mode&&_(function(t){var o=null!=e&&e.matches?"dark":"light";return t.systemMode===o?t:(0,r.Z)((0,r.Z)({},t),{},{systemMode:o})})},[U.mode]),(Q=m.useRef(J)).current=J,m.useEffect(function(){var e=function(){return Q.current.apply(Q,arguments)},t=window.matchMedia("(prefers-color-scheme: dark)");return t.addListener(e),e(t),function(){t.removeListener(e)}},[]),m.useEffect(function(){if(R){var e=function(e){var t=e.newValue;"string"==typeof e.key&&e.key.startsWith(P)&&(!t||N.match(t))&&(e.key.endsWith("light")&&q({light:t}),e.key.endsWith("dark")&&q({dark:t})),e.key===z&&(!t||["light","dark","system"].includes(t))&&G(t||d)};return R.addEventListener("storage",e),function(){R.removeEventListener("storage",e)}}},[q,G,z,P,N,d,R]),(0,r.Z)((0,r.Z)({},U),{},{colorScheme:$,setMode:G,setColorScheme:q})),eK=ej.mode,eP=ej.setMode,eO=ej.systemMode,eR=ej.lightColorScheme,eN=ej.darkColorScheme,eT=ej.colorScheme,eL=ej.setColorScheme,eU=eK,e_=eT;ek&&(eU=eZ.mode,e_=eZ.colorScheme);var e$=eU||("system"===el?A:el),eG=e_||("dark"===e$?eV:eW),eq=eA(),eJ=eq.css,eQ=eq.vars,eX=(0,r.Z)((0,r.Z)({},ez),{},{components:void 0===eH?{}:eH,colorSchemes:eD,cssVarPrefix:eI,vars:eQ,getColorSchemeSelector:function(e){return"[".concat(ea,'="').concat(e,'"] &')}}),eY={},e0={};u()(eD).forEach(function(e){var t=(0,a.Z)(e,2),o=t[0],n=t[1],l=eA(o),i=l.css,c=l.vars;if(eX.vars=(0,v.Z)(eX.vars,c),o===eG&&(s()(n).forEach(function(e){n[e]&&"object"==typeof n[e]?eX[e]=(0,r.Z)((0,r.Z)({},eX[e]),n[e]):eX[e]=n[e]}),eX.palette&&(eX.palette.colorScheme=o)),o===("string"==typeof ec?ec:"dark"===el?ec.dark:ec.light)){if(V){var d={};V(eI).forEach(function(e){d[e]=i[e],delete i[e]}),eY["[".concat(ea,'="').concat(o,'"]')]=d}eY["".concat(ey,", [").concat(ea,'="').concat(o,'"]')]=i}else e0["".concat(":root"===ey?"":ey,"[").concat(ea,'="').concat(o,'"]')]=i}),eX.vars=(0,v.Z)(eX.vars,eQ),m.useEffect(function(){e_&&ep&&ep.setAttribute(ea,e_)},[e_,ea,ep]),m.useEffect(function(){var e;if(ed&&eb.current&&eh){var t=eh.createElement("style");t.appendChild(eh.createTextNode("*{-webkit-transition:none!important;-moz-transition:none!important;-o-transition:none!important;-ms-transition:none!important;transition:none!important}")),eh.head.appendChild(t),window.getComputedStyle(eh.body),e=setTimeout(function(){eh.head.removeChild(t)},1)}return function(){clearTimeout(e)}},[e_,ed,eh]),m.useEffect(function(){return eb.current=!0,function(){eb.current=!1}},[]);var e1=m.useMemo(function(){return{allColorSchemes:eM,colorScheme:e_,darkColorScheme:eN,lightColorScheme:eR,mode:eU,setColorScheme:eL,setMode:eP,systemMode:eO}},[eM,e_,eN,eR,eU,eL,eP,eO]),e5=!0;(void 0!==eC&&eC||ek&&(null==ex?void 0:ex.cssVarPrefix)===eI)&&(e5=!1);var e2=(0,g.jsxs)(m.Fragment,{children:[e5&&(0,g.jsxs)(m.Fragment,{children:[(0,g.jsx)(h.Z,{styles:(0,n.Z)({},ey,eJ)}),(0,g.jsx)(h.Z,{styles:eY}),(0,g.jsx)(h.Z,{styles:e0})]}),(0,g.jsx)(p.Z,{themeId:eF?t:void 0,theme:W?W(eX):eX,children:X})]});return ek?e2:(0,g.jsx)(j.Provider,{value:e1,children:e2})},useColorScheme:function(){var e=m.useContext(j);if(!e)throw Error((0,i.Z)(19));return e},getInitColorSchemeScript:function(e){var t,o,n,a,l,i,c,s,d,u,m,v,h,f,p;return n=void 0===(o=(t=(0,r.Z)({attribute:F,colorSchemeStorageKey:H,defaultMode:A,defaultLightColorScheme:K,defaultDarkColorScheme:P,modeStorageKey:w},e)||{}).defaultMode)?"light":o,l=void 0===(a=t.defaultLightColorScheme)?"light":a,c=void 0===(i=t.defaultDarkColorScheme)?"dark":i,d=void 0===(s=t.modeStorageKey)?y:s,m=void 0===(u=t.colorSchemeStorageKey)?S:u,h=void 0===(v=t.attribute)?C:v,p=void 0===(f=t.colorSchemeNode)?"document.documentElement":f,(0,g.jsx)("script",{dangerouslySetInnerHTML:{__html:"(function() {\ntry {\n  var mode = localStorage.getItem('".concat(d,"') || '").concat(n,"';\n  var colorScheme = '';\n  if (mode === 'system') {\n    // handle system mode\n    var mql = window.matchMedia('(prefers-color-scheme: dark)');\n    if (mql.matches) {\n      colorScheme = localStorage.getItem('").concat(m,"-dark') || '").concat(c,"';\n    } else {\n      colorScheme = localStorage.getItem('").concat(m,"-light') || '").concat(l,"';\n    }\n  }\n  if (mode === 'light') {\n    colorScheme = localStorage.getItem('").concat(m,"-light') || '").concat(l,"';\n  }\n  if (mode === 'dark') {\n    colorScheme = localStorage.getItem('").concat(m,"-dark') || '").concat(c,"';\n  }\n  if (colorScheme) {\n    ").concat(p,".setAttribute('").concat(h,"', colorScheme);\n  }\n} catch(e){}})();")}},"mui-color-scheme-init")}}}},793975:function(e,t,o){o.d(t,{Z:function(){return a}});var n=o(362493);function a(){var e=arguments.length>0&&void 0!==arguments[0]?arguments[0]:"";function t(){for(var o=arguments.length,a=Array(o),r=0;r<o;r++)a[r]=arguments[r];if(!a.length)return"";var l=a[0];return"string"!=typeof l||l.match(/(#|\(|\)|(-?(\d*\.)?\d+)(px|em|%|ex|ch|rem|vw|vh|vmin|vmax|cm|mm|in|pt|pc))|^(-?(\d*\.)?\d+)$|(\d+ \d+ \d+)/)?", ".concat(l):", var(--".concat(e?"".concat(e,"-"):"").concat(l).concat(t.apply(void 0,(0,n.Z)(a.slice(1))),")")}return function(o){for(var n=arguments.length,a=Array(n>1?n-1:0),r=1;r<n;r++)a[r-1]=arguments[r];return"var(--".concat(e?"".concat(e,"-"):"").concat(o).concat(t.apply(void 0,a),")")}}},68468:function(e,t,o){o.d(t,{ZP:function(){return f}});var n=o(974468),a=o(176905),r=o(362493),l=o(535630),i=o(557428),c=o.n(i),s=o(456765),d=o.n(s),u=o(512815),m=o.n(u),v=function(e,t,o){var n=arguments.length>3&&void 0!==arguments[3]?arguments[3]:[],a=e;t.forEach(function(e,r){r===t.length-1?c()(a)?a[Number(e)]=o:a&&"object"==typeof a&&(a[e]=o):a&&"object"==typeof a&&(a[e]||(a[e]=n.includes(e)?[]:{}),a=a[e])})},h=function(e,t,o){!function e(n){var a=arguments.length>1&&void 0!==arguments[1]?arguments[1]:[],i=arguments.length>2&&void 0!==arguments[2]?arguments[2]:[];d()(n).forEach(function(n){var s=(0,l.Z)(n,2),d=s[0],u=s[1];o&&(!o||o([].concat((0,r.Z)(a),[d])))||null==u||("object"==typeof u&&m()(u).length>0?e(u,[].concat((0,r.Z)(a),[d]),c()(u)?[].concat((0,r.Z)(i),[d]):i):t([].concat((0,r.Z)(a),[d]),u,i))})}(e)};function f(e,t){var o=t||{},r=o.prefix,l=o.shouldSkipGeneratingVar,i={},c={},s={};return h(e,function(e,t,o){if(("string"==typeof t||"number"==typeof t)&&(!l||!l(e,t))){var d="--".concat(r?"".concat(r,"-"):"").concat(e.join("-"));(0,a.Z)(i,(0,n.Z)({},d,"number"==typeof t?["lineHeight","fontWeight","opacity","zIndex"].some(function(t){return e.includes(t)})||e[e.length-1].toLowerCase().indexOf("opacity")>=0?t:"".concat(t,"px"):t)),v(c,e,"var(".concat(d,")"),o),v(s,e,"var(".concat(d,", ").concat(t,")"),o)}},function(e){return"vars"===e[0]}),{css:i,vars:c,varsWithDefaults:s}}},371340:function(e,t,o){var n=o(41732),a=o(535630),r=o(867803),l=o(532534),i=o(456765),c=o.n(i),s=o(357814),d=o(68468),u=["colorSchemes","components","defaultColorScheme"];t.Z=function(e,t){var o=e.colorSchemes,i=void 0===o?{}:o,m=(e.components,e.defaultColorScheme),v=void 0===m?"light":m,h=(0,l.Z)(e,u),f=(0,d.ZP)(h,t),p=f.vars,g=f.css,y=f.varsWithDefaults,S={},C=i[v],b=(0,l.Z)(i,[v].map(r.Z));if(c()(b||{}).forEach(function(e){var o=(0,a.Z)(e,2),n=o[0],r=o[1],l=(0,d.ZP)(r,t),i=l.vars,c=l.css,u=l.varsWithDefaults;y=(0,s.Z)(y,u),S[n]={css:c,vars:i}}),C){var x=(0,d.ZP)(C,t),Z=x.css,k=x.vars,F=x.varsWithDefaults;y=(0,s.Z)(y,F),S[v]={css:Z,vars:k}}return{vars:y,generateCssVars:function(e){if(!e){var o,a,r=(0,n.Z)({},g);return{css:r,vars:p,selector:(null==t?void 0:null===(a=t.getSelector)||void 0===a?void 0:a.call(t,e,r))||":root"}}var l=(0,n.Z)({},S[e].css);return{css:l,vars:S[e].vars,selector:(null==t?void 0:null===(o=t.getSelector)||void 0===o?void 0:o.call(t,e,l))||":root"}}}}}}]);