"use strict";(self.webpackChunk_N_E=self.webpackChunk_N_E||[]).push([[27762],{342479:function(t,e,n){var r=n(12380),o=n(319127),a=n(930658),i=n(422688),s=n(816306),c=(0,a.Z)(),u=(0,r.Z)({themeId:i.Z,defaultTheme:c,defaultClassName:s.Z.root,generateClassName:o.Z.generate});e.Z=u},816306:function(t,e,n){var r=(0,n(983433).Z)("MuiBox",["root"]);e.Z=r},823822:function(t,e,n){n.d(e,{d1:function(){return m},dy:function(){return p}});var r=n(535630),o=n(41732),a=n(456765),i=n.n(a),s=n(470079),c=n(261659),u=n(272537),l=n(735250),p=function(t,e){return(0,o.Z)({WebkitFontSmoothing:"antialiased",MozOsxFontSmoothing:"grayscale",boxSizing:"border-box",WebkitTextSizeAdjust:"100%"},e&&!t.vars&&{colorScheme:t.palette.mode})},m=function(t){return(0,o.Z)((0,o.Z)({color:(t.vars||t).palette.text.primary},t.typography.body1),{},{backgroundColor:(t.vars||t).palette.background.default,"@media print":{backgroundColor:(t.vars||t).palette.common.white}})},d=function(t){var e,n,a=arguments.length>1&&void 0!==arguments[1]&&arguments[1],s={};a&&t.colorSchemes&&i()(t.colorSchemes).forEach(function(e){var n,o=(0,r.Z)(e,2),a=o[0],i=o[1];s[t.getColorSchemeSelector(a).replace(/\s*&/,"")]={colorScheme:null===(n=i.palette)||void 0===n?void 0:n.mode}});var c=(0,o.Z)({html:p(t,a),"*, *::before, *::after":{boxSizing:"inherit"},"strong, b":{fontWeight:t.typography.fontWeightBold},body:(0,o.Z)((0,o.Z)({margin:0},m(t)),{},{"&::backdrop":{backgroundColor:(t.vars||t).palette.background.default}})},s),u=null===(e=t.components)||void 0===e?void 0:null===(n=e.MuiCssBaseline)||void 0===n?void 0:n.styleOverrides;return u&&(c=[c,u]),c};e.ZP=function(t){var e=(0,c.Z)({props:t,name:"MuiCssBaseline"}),n=e.children,r=e.enableColorScheme,o=void 0!==r&&r;return(0,l.jsxs)(s.Fragment,{children:[(0,l.jsx)(u.Z,{styles:function(t){return d(t,o)}}),n]})}},272537:function(t,e,n){var r=n(41732);n(470079);var o=n(914667),a=n(925280),i=n(422688),s=n(735250);e.Z=function(t){return(0,s.jsx)(o.Z,(0,r.Z)((0,r.Z)({},t),{},{defaultTheme:a.Z,themeId:i.Z}))}},274982:function(t,e,n){var r=n(532534),o=n(41732),a=n(470079),i=n(969577),s=n(538874),c=n(12914),u=n(457095),l=n(261659),p=n(353935),m=n(628939),d=n(735250),h=["align","className","component","gutterBottom","noWrap","paragraph","variant","variantMapping"],v=function(t){var e=t.align,n=t.gutterBottom,r=t.noWrap,o=t.paragraph,a=t.variant,i=t.classes,s={root:["root",a,"inherit"!==t.align&&"align".concat((0,p.Z)(e)),n&&"gutterBottom",r&&"noWrap",o&&"paragraph"]};return(0,c.Z)(s,m.f,i)},g=(0,u.ZP)("span",{name:"MuiTypography",slot:"Root",overridesResolver:function(t,e){var n=t.ownerState;return[e.root,n.variant&&e[n.variant],"inherit"!==n.align&&e["align".concat((0,p.Z)(n.align))],n.noWrap&&e.noWrap,n.gutterBottom&&e.gutterBottom,n.paragraph&&e.paragraph]}})(function(t){var e=t.theme,n=t.ownerState;return(0,o.Z)((0,o.Z)((0,o.Z)((0,o.Z)((0,o.Z)((0,o.Z)({margin:0},"inherit"===n.variant&&{font:"inherit"}),"inherit"!==n.variant&&e.typography[n.variant]),"inherit"!==n.align&&{textAlign:n.align}),n.noWrap&&{overflow:"hidden",textOverflow:"ellipsis",whiteSpace:"nowrap"}),n.gutterBottom&&{marginBottom:"0.35em"}),n.paragraph&&{marginBottom:16})}),f={h1:"h1",h2:"h2",h3:"h3",h4:"h4",h5:"h5",h6:"h6",subtitle1:"h6",subtitle2:"h6",body1:"p",body2:"p",inherit:"p"},Z={primary:"primary.main",textPrimary:"text.primary",secondary:"secondary.main",textSecondary:"text.secondary",error:"error.main"},y=a.forwardRef(function(t,e){var n,a=(0,l.Z)({props:t,name:"MuiTypography"}),c=Z[n=a.color]||n,u=(0,s.Z)((0,o.Z)((0,o.Z)({},a),{},{color:c})),p=u.align,m=u.className,y=u.component,x=u.gutterBottom,b=u.noWrap,j=u.paragraph,w=void 0!==j&&j,S=u.variant,P=void 0===S?"body1":S,B=u.variantMapping,C=void 0===B?f:B,N=(0,r.Z)(u,h),T=(0,o.Z)((0,o.Z)({},u),{},{align:void 0===p?"inherit":p,color:c,className:m,component:y,gutterBottom:void 0!==x&&x,noWrap:void 0!==b&&b,paragraph:w,variant:P,variantMapping:C}),W=y||(w?"p":C[P]||f[P])||"span",k=v(T);return(0,d.jsx)(g,(0,o.Z)({as:W,ref:e,ownerState:T,className:(0,i.default)(k.root,m)},N))});e.Z=y},628939:function(t,e,n){n.d(e,{f:function(){return a}});var r=n(983433),o=n(743064);function a(t){return(0,o.ZP)("MuiTypography",t)}var i=(0,r.Z)("MuiTypography",["root","h1","h2","h3","h4","h5","h6","subtitle1","subtitle2","body1","body2","inherit","button","caption","overline","alignLeft","alignRight","alignCenter","alignJustify","noWrap","gutterBottom","paragraph"]);e.Z=i},940718:function(t,e,n){n.d(e,{Z:function(){return s}});var r=n(512815),o=n.n(r);n(470079);var a=n(616887),i=n(735250);function s(t){var e=t.styles,n=t.defaultTheme,r=void 0===n?{}:n,s="function"==typeof e?function(t){return e(null==t||0===o()(t).length?r:t)}:e;return(0,i.jsx)(a.Global,{styles:s})}},914667:function(t,e,n){n(470079);var r=n(940718),o=n(267054),a=n(735250);e.Z=function(t){var e=t.styles,n=t.themeId,i=t.defaultTheme,s=(0,o.Z)(void 0===i?{}:i),c="function"==typeof e?e(n&&s[n]||s):e;return(0,a.jsx)(r.Z,{styles:c})}},12380:function(t,e,n){n.d(e,{Z:function(){return d}});var r=n(41732),o=n(532534),a=n(470079),i=n(969577),s=n(348036),c=n(296106),u=n(538874),l=n(267054),p=n(735250),m=["className","component"];function d(){var t=arguments.length>0&&void 0!==arguments[0]?arguments[0]:{},e=t.themeId,n=t.defaultTheme,d=t.defaultClassName,h=void 0===d?"MuiBox-root":d,v=t.generateClassName,g=(0,s.ZP)("div",{shouldForwardProp:function(t){return"theme"!==t&&"sx"!==t&&"as"!==t}})(c.Z);return a.forwardRef(function(t,a){var s=(0,l.Z)(n),c=(0,u.Z)(t),d=c.className,f=c.component,Z=(0,o.Z)(c,m);return(0,p.jsx)(g,(0,r.Z)({as:void 0===f?"div":f,ref:a,className:(0,i.default)(d,v?v(h):h),theme:e&&s[e]||s},Z))})}},538874:function(t,e,n){n.d(e,{Z:function(){return h}});var r=n(41732),o=n(362493),a=n(532534),i=n(512815),s=n.n(i),c=n(557428),u=n.n(c),l=n(357814),p=n(533347),m=["sx"],d=function(t){var e,n,r={systemProps:{},otherProps:{}},o=null!==(e=null==t?void 0:null===(n=t.theme)||void 0===n?void 0:n.unstable_sxConfig)&&void 0!==e?e:p.Z;return s()(t).forEach(function(e){o[e]?r.systemProps[e]=t[e]:r.otherProps[e]=t[e]}),r};function h(t){var e,n=t.sx,i=d((0,a.Z)(t,m)),s=i.systemProps,c=i.otherProps;return e=u()(n)?[s].concat((0,o.Z)(n)):"function"==typeof n?function(){var t=n.apply(void 0,arguments);return(0,l.P)(t)?(0,r.Z)((0,r.Z)({},s),t):s}:(0,r.Z)((0,r.Z)({},s),n),(0,r.Z)((0,r.Z)({},c),{},{sx:e})}},307115:function(t,e,n){n.d(e,{Z:function(){return v}});var r,o,a,i=n(606598),s=n.n(i),c=n(649052),u=n(343019),l=n(617901),p=n(61212),m=n(735250),d=n(444675),h=d.env.PULL_REQUEST_ID?"https://deploy-preview-".concat(d.env.PULL_REQUEST_ID,"--").concat("material-ui-docs",".netlify.app"):"https://mui.com";function v(t){var e=(0,l.useTranslate)(),n=t.card,i=void 0===n?"/static/social-previews/home-preview.jpg":n,d=t.children,v=t.description,g=void 0===v?e("strapline"):v,f=t.disableAlternateLocale,Z=t.largeCard,y=t.title,x=void 0===y?e("headTitle"):y,b=t.type,j=(0,l.useUserLanguage)(),w=(0,c.useRouter)(),S=(0,p.ln)(w.asPath).canonicalAs,P=i.startsWith("http")?i:"".concat(h).concat(i);return(0,m.jsxs)(s(),{children:[(0,m.jsx)("title",{children:x}),(0,m.jsx)("meta",{name:"description",content:g}),(0,m.jsx)("meta",{name:"twitter:card",content:void 0===Z||Z?"summary_large_image":"summary"}),r||(r=(0,m.jsx)("meta",{name:"twitter:site",content:"@MUI_hq"})),(0,m.jsx)("meta",{name:"twitter:title",content:x}),(0,m.jsx)("meta",{name:"twitter:description",content:g}),(0,m.jsx)("meta",{name:"twitter:image",content:P}),(0,m.jsx)("meta",{property:"og:type",content:void 0===b?"website":b}),(0,m.jsx)("meta",{property:"og:title",content:x}),(0,m.jsx)("meta",{property:"og:url",content:"".concat(h).concat(w.asPath)}),(0,m.jsx)("meta",{property:"og:description",content:g}),(0,m.jsx)("meta",{property:"og:image",content:P}),o||(o=(0,m.jsx)("meta",{property:"og:ttl",content:"604800"})),(0,m.jsx)("meta",{name:"docsearch:language",content:j}),a||(a=(0,m.jsx)("meta",{name:"docsearch:version",content:"master"})),void 0!==f&&f?null:u.LANGUAGES_SSR.map(function(t){return(0,m.jsx)("link",{rel:"alternate",href:"https://mui.com".concat("en"===t?"":"/".concat(t)).concat(S),hrefLang:t},t)}),d]})}}}]);