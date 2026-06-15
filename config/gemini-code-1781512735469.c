/* ==========================================================================
 * ZMK KEYMAP - CORNE - ADOLF (Punto Dulce / Optimizado)
 * ========================================================================== */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/keys.h>

#define DEFAULT 0
#define RAISE   1
#define LOWER   2
#define FUNC    3
#define NAV     4
#define NUM     5
#define SYS     6

/ {
    behaviors {
        Ene_ene: Ene_ene { 
            compatible = "zmk,behavior-tap-dance"; label = "ENE_ENE"; #binding-cells = <0>;
            bindings = <&kp N>, <&kp RA(N)>; 
        };

        Hm: Hm { 
            compatible = "zmk,behavior-hold-tap"; label = "HM"; #binding-cells = <2>;
            bindings = <&kp>, <&kp>; 
            tapping-term-ms = <250>; quick-tap-ms = <0>; flavor = "tap-preferred"; 
        };

        Apadago: Apadago { 
            compatible = "zmk,behavior-tap-dance"; label = "APADAGO"; #binding-cells = <0>;
            bindings = <&none>, <&soft_off>; tapping-term-ms = <300>; 
        };

        Bt1: Bt1 { compatible = "zmk,behavior-tap-dance"; label = "BT1"; #binding-cells = <0>; bindings = <&none>, <&bt BT_SEL 0>; };
        BT2: BT2 { compatible = "zmk,behavior-tap-dance"; label = "BT2"; #binding-cells = <0>; bindings = <&none>, <&bt BT_SEL 1>; };
        BT3: BT3 { compatible = "zmk,behavior-tap-dance"; label = "BT3"; #binding-cells = <0>; bindings = <&none>, <&bt BT_SEL 2>; };
        BTAll: BTAll { compatible = "zmk,behavior-tap-dance"; label = "BTALL"; #binding-cells = <0>; bindings = <&none>, <&bt BT_CLR_ALL>; };
    };

    macros {
        Captura: M1 { compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&kp LG(LS(S))>; label = "M1"; };
    };

    combos {
        compatible = "zmk,combos";
        Backspace { bindings = <&kp BACKSPACE>; key-positions = <19 20>; };
        Copiar { bindings = <&kp LC(C)>; key-positions = <3 2>; };
        Pegar { bindings = <&kp LC(V)>; key-positions = <14 15>; };
        Cortar { bindings = <&kp LC(X)>; key-positions = <2 3 4>; };
        pegarTex { bindings = <&kp LC(LS(V))>; key-positions = <14 15 16>; };
        Borrar_pal { bindings = <&kp LC(BACKSPACE)>; key-positions = <19 20 21>; };
        PageUp { bindings = <&kp PAGE_UP>; key-positions = <8 9>; require-prior-idle-ms = <40>; };
        PageDown { bindings = <&kp PAGE_DOWN>; key-positions = <32 33>; require-prior-idle-ms = <40>; };
        Home { bindings = <&kp HOME>; key-positions = <7 8 9>; };
        End { bindings = <&kp END>; key-positions = <31 32 33>; };
        delete { bindings = <&kp DEL>; key-positions = <7 8>; };
        SoftOff { bindings = <&soft_off>; key-positions = <0 29>; };
        CommandPal { bindings = <&kp LA(LG(SPACE))>; key-positions = <26 27 28>; };
        btclear { bindings = <&bt BT_CLR_ALL>; key-positions = <1 4>; layers = <SYS>; };
    };

    keymap {
        compatible = "zmk,keymap";
        default_layer = <DEFAULT>;

        DEFAULT { bindings = <
            &kp ESCAPE &kp Q &kp W &kp E &kp R &kp T &kp Y &kp U &kp I &kp O &kp P &kp DEL
            &mt LEFT_ALT CAPS &Hm LCTRL A &Hm LALT S &Hm LEFT_SHIFT D &Hm LEFT_GUI F &lt SYS G &kp H &Hm LEFT_GUI J &Hm LEFT_SHIFT K &Hm LEFT_ALT L &Hm LCTRL SEMICOLON &kp SQT
            &kp LCTRL &kp Z &kp X &kp C &kp V &kp B &Ene_ene &kp M &kp COMMA &kp DOT &kp FSLH &mt RIGHT_ALT BACKSPACE
            &kp LGUI &mo RAISE &mt LSHIFT ENTER &mt LSHIFT SPACE &mo LOWER &mo NAV >; };

        RAISE { bindings = <
            &kp ESC &kp LEFT_WIN &kp PAGE_DOWN &kp UP_ARROW &kp PAGE_UP &kp DEL &kp PLUS &kp N7 &kp N8 &kp N9 &kp ASTRK &trans
            &kp LALT &kp SPACE &kp LEFT_ARROW &kp DOWN_ARROW &kp RIGHT &kp BACKSPACE &kp MINUS &kp NUMBER_4 &kp N5 &kp NUMBER_6 &kp SLASH &kp COLON
            &trans &kp LS(LG(LEFT)) &kp LS(LG(RIGHT_ARROW)) &kp LC(LG(LEFT_ARROW)) &kp LC(LG(RIGHT)) &kp LG(LS(S)) &kp N0 &kp NUMBER_1 &kp NUMBER_2 &kp NUMBER_3 &kp KP_DOT &trans
            &trans &trans &trans &trans &trans &trans >; };

        LOWER { bindings = <
            &kp ESC &kp EXCL &kp AT &kp HASH &kp DOLLAR &kp PERCENT &kp PLUS &kp AMPERSAND &kp LEFT_BRACE &kp RIGHT_BRACE &kp BACKSLASH &trans
            &trans &kp TILDE &kp CARET &kp APOS &kp LESS_THAN &kp GREATER_THAN &kp MINUS &kp EQUAL &kp LEFT_PARENTHESIS &kp RIGHT_PARENTHESIS &kp PIPE &kp SINGLE_QUOTE
            &trans &kp RA(RS(SEMI)) &none &kp DOUBLE_QUOTES &none &Captura &kp UNDERSCORE &kp ASTERISK &kp LEFT_BRACKET &kp RIGHT_BRACKET &kp SLASH &trans
            &trans &trans &trans &trans &trans &trans >; };

        FUNC { bindings = <
            &trans &trans &trans &trans &trans &trans &trans &kp F7 &kp F8 &kp F9 &kp F10 &trans
            &trans &trans &trans &trans &trans &trans &trans &kp F4 &kp F5 &kp F6 &kp F11 &trans
            &trans &trans &trans &trans &trans &trans &trans &kp F1 &kp F2 &kp F3 &kp F12 &kp LEFT_ALT
            &trans &trans &trans &trans &trans &trans >; };

        NAV { bindings = <
            &trans &trans &kp LC(UP) &kp LC(PAGE_UP) &kp LC(HOME) &kp LC(LS(TAB)) &trans &kp LC(PAGE_UP) &kp LC(PAGE_DOWN) &none &none &trans
            &none &none &kp LC(DOWN_ARROW) &kp LC(PAGE_DOWN) &kp LC(END) &kp LC(TAB) &trans &kp C_VOL_DN &kp C_VOLUME_UP &kp C_PLAY_PAUSE &none &trans
            &trans &none &none &kp LC(LEFT) &kp LC(RIGHT) &none &trans &kp DEL &kp C_MUTE &trans &none &trans
            &trans &trans &trans &trans &trans &trans >; };

        NUM { bindings = <
            &trans &kp NUMBER_1 &kp NUMBER_2 &kp NUMBER_3 &kp NUMBER_4 &kp N5 &kp NUMBER_6 &kp N7 &kp N8 &kp NUMBER_9 &kp N0 &trans
            &trans &kp LS(NUMBER_1) &kp LS(NUMBER_2) &kp LS(NUMBER_3) &kp LS(NUMBER_4) &kp LS(N5) &kp LS(NUMBER_6) &kp LS(N7) &kp LS(N8) &kp LS(N9) &kp LS(N0) &trans
            &trans &trans &trans &trans &trans &trans &trans &trans &trans &trans &trans &trans
            &trans &trans &trans &trans &trans &trans >; };

        SYS { bindings = <
            &trans &Bt1 &BT2 &BT3 &BTAll &trans &trans &kp F13 &kp F14 &kp F15 &trans &trans
            &trans &Apadago &trans &trans &trans &trans &trans &kp F16 &kp F17 &kp F18 &trans &trans
            &trans &trans &trans &trans &trans &none &kp A &kp F19 &kp F20 &kp F21 &trans &trans
            &trans &trans &trans &kp F22 &kp F23 &kp F24 >; };
    };

    conditional_layers {
        compatible = "zmk,conditional-layers";
        capa_num { if-layers = <RAISE NAV>; then-layer = <NUM>; };
        capa_func { if-layers = <RAISE LOWER>; then-layer = <FUNC>; };
    };
};