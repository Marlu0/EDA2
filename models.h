/*notes about the art. they need to be roughly the same size and style. first style is prob the easiest
make sure to name all the arts in a similar way the first one is named so that we can just type the name to use it.
we only need 4 enemy types and our character model.
there should be the close up duel model and the far away world map model.
tmbn cada vez k hay una \ en el string tienes k pone doble.
to find out implentation fo the dictionary
*/

/*IDEAS:
we will need a function that displaces a certain drawing to the left or right by adding tabs and spaces to the front.
*/


#include "common.h"

#define DRAWING_LEN 1000 //we can change this is we want the drawings bigger,
#define NAME_LEN 20

//might also want to create a dictionary that stores all models.

typedef char Model[DRAWING_LEN];

//lizard works
Model lizard = {"               _____\n              |     |\n            \\_|_____|_/     /|\n            .'()..()`.    / /\n           ( `-.__.-' )  ( (\n            \\        /    \\ \\\n             \\      /      ) )\n           .' -.__.- `.-.-'_.'\n         .'  /-____-\\  `.-'\n         \\  /-.____.-\\  /-.\n          \\ \\`-.__.-'/ /\\|\\|\n         .'  `.    .'  `.\n         |/\\/\\|    |/\\/\\|\n\n"};
/*            _____           
             |     |
           \_|_____|_/     /|
            .'()..()`.    / /
           ( `-.__.-' )  ( ( 
            \        /    \ \
             \      /      ) )
           .' -.__.- `.-.-'_.'
         .'  /-____-\  `.-'    
         \  /-.____.-\  /-.
          \ \`-.__.-'/ /\|\|   
         .'  `.    .'  `.
         |/\/\|    |/\/\|
*/
Model box = {"┌─────────┐\n│         │\n└─────────┘\n"};

/*┌─────────┐
  │         │
  └─────────┘
*/
Model snake = {"           _____\n          |$    |\n        \\_|_____|_/\n           /^\\/^\\\n         _|__|  O|\n\\/     /~     \\_/ \\\n \\____|__________/ \\\n        \\_______    \\\n                `\\   \\                       \\\n                 /    )                       \\\n               /     /                         \\\n             /     /                           \\ \\\n           /     /             _------_         \\  \\\n         (      (        _-~    _--_    ~-_    _/  |\n          \\      ~-____-~    _-~    ~-_    ~-_-~   /\n            ~-_           _-~          ~-_      _-~\n               ~--______-~                ~-__-~\n\n"};
/*
           _____
          |$    |
        \_|_____|_/
           /^\/^\
         _|__|  O|
\/     /~     \_/ \
 \____|__________/  \
        \_______     \
                `\    \                    \
                 /     )                    \
                /     /                      \\
             /     /                          \ \
           /     /             _------_         \  \
         (      (        _-~    _--_    ~-_    _/  |
          \      ~-____-~    _-~    ~-_    ~-_-~   /
            ~-_           _-~          ~-_      _-~
               ~--______-~                ~-__-~

_______________________________________________________________________________
                          .-|-|----------------|-|-.
                          | .-. .-. .  .-. .-. . . |_
                     .--~~| `-. |-| |  | | | | |\| | ~~--.
                     |    | `-' ` ' `- `-' `-' ' ' |     |
                     |    `-.____________________.-'     |
_______________      |                                   |
     |         |     |                                   |
  /  |   /  /  |     |                                   |
/    |     /   |     | _______                   _______ |
_____|_________|     ||       ~---_         _---~       ||
     |    /    |     ||           ~---. .---~           ||
 / / |         |     ||               | |               ||
  /  |  /   /  |     ||               | |               ||
_____|_________|     ||               | |               ||
---------------'     ||               | |               ||
                     ||               | |               ||
                     ||               | |               ||
                     ||           .---' `---.           ||
                     |`.______.---'         `---.______.'|
               ______|                                   |______
--------~~~~~~~                                                 ~~~~~~~--------

                                               _
                 ___                          (_)
               _/XXX\
_             /XXXXXX\_                                    __
X\__    __   /X XXXX XX\                          _       /XX\__      ___
    \__/  \_/__       \ \                       _/X\__   /XX XXX\____/XXX\
  \  ___   \/  \_      \ \               __   _/      \_/  _/  -   __  -  \__/
 ___/   \__/   \ \__     \\__           /  \_//  _ _ \  \     __  /  \____//
/  __    \  /     \ \_   _//_\___     _/    //           \___/  \/     __/
__/_______\________\__\_/________\_  _/_____/_____________/_______\____/_______
                                  /  \
                                 /    \
                                /      \
                               /        \
                              /          \
                             /            \
                            /              \
                           /                \
                          /                  \
                         /                    \

                /||\
                ||||
                ||||                      _____.-..-.
                |||| /|\               .-~@@/ / q  p \
           /|\  |||| |||             .'@ _@/..\-.__.-/
           |||  |||| |||            /@.-~/|~~~`\|__|/
           |||  |||| |||            |'--<||     '~~'
           |||  |||| d||            |>--<\@\
           |||  |||||||/            \>---<\@`\.
           ||b._||||~~'              `\>---<`\@`\.
           \||||||||                   `\>----<`\@`\.
            `~~~||||               _     `\>-----<`\@`\.
                ||||              (_)      `\>-----<`\.@`\.
                ||||              (_)        `\>------<`\.@`\.
~~~~~~~~~~~~~~~~||||~~~~~~~~~~~~~~(__)~~~~~~~~~`\>-------<`\.@`\~~~~~~~~~~~~~
  \/..__..--  . |||| \/  .  ..____( _)@@@--..____\..--\@@@/~`\@@>-._   \/ .
\/         \/ \/    \/     / - -\@@@@--@/- - \@@@/ - - \@/- -@@@@/- \.   --._
   .   \/    _..\/-...--.. |- - -\@@/ - -\@@@@/~~~~\@@@@/- - \@@/- - |   .\/
        .  \/              | - - -@@ - - -\@@/- - - \@@/- - - @@- - -|      .
. \/             .   \/     ~-.__ - - - - -@@- - - - @@- - - - -__.-~  . \/
   __...--..__..__       .  \/   ~~~--..____- - - - -____..--~~~    \/_..--..
\/  .   .    \/     \/    __..--... \/      ~~~~~~~~~     \/ . \/  .

                              .-.
                             (  o)-.
                              ) )\|\)
                           _./ (,_ 
                          ( '**"  )
                          \\\   ///
                           \\\|///
                     _______//|\\____________               .
                   ,'______///|\\\________,'|            \  :  /
     _ _           |  ____________________|,'             ' _ '
    ' Y ' _ _      | ||              |                -= ( (_) )=-
    _ _  ' Y '     | ||              |                    .   .
   ' Y '_ _        | ||              |                   /  :  \
       ( Y )       | ||              8                      '
                   | ||              8
                   | ||        /\/\  8
                   | ||      .'   ``/|
                   | ||      | x   ``|
                   | ||      |  /. `/` 
                   | ||      '_/|  /```                 .-.
                   | ||        (_,' ````                |.|
  |J               | ||         |       \             /)|`|(\
 L|                | ||       ,'         \           (.(|'|)`)
  |                | ||     ,','| .'      \           `\`'./'
~~~~~~~~~~~~~~~~~~~| ||~~~~~||~~||.       \~~~~~~~~~~~~~|.|~~~~~~~~~~~ 
                   | ||     ||  || \        \          ,|`|.
  ~~               | ||     ""  ""  \        \          "'"   ~~
                   | ||              )   .   )   
                   | ||             / ,   ),'|      ~~
             ~~    | ||         ___/ /   ,'  |              (_)
      ((__))       | ||   ~~   I____/  ,'    |              /"/
      ( 0 0)       | ||         I____,'      *             ^~^
       `\_\\       | ||                          ~~
         "'"'      | ||  
  ~~               | ||         ~~                          ~~
                   |_|/

    .    _    +     .  ______   .          .
 (      /|\      .    |      \      .   +
     . |||||     _    | |   | | ||         .
.      |||||    | |  _| | | | |_||    .
   /\  ||||| .  | | |   | |      |       .
__||||_|||||____| |_|_____________\__________
. |||| |||||  /\   _____      _____  .   .
  |||| ||||| ||||   .   .  .         ________
 . \|`-'|||| ||||    __________       .    .
    \__ |||| ||||      .          .     .
 __    ||||`-'|||  .       .    __________
.    . |||| ___/  ___________             .
   . _ ||||| . _               .   _________
_   ___|||||__  _ \\--//    .          _
     _ `---'    .)=\oo|=(.   _   .   .    .
_  ^      .  -    . \.|

                                                      ____
                                                     /    `.
                                                    /-----.|          ____
                                                ___/___.---`--.__.---'    `--.
                                  _______.-----'           __.--'             )
                              ,--'---.______________..----'(  __         __.-'
                                        `---.___,-.|(a (a) /-'  )___.---'
                                                `-.>------<__.-'
            ______                       _____..--'      //
    __.----'      `---._                `._.--._______.-'/))
,--'---.__              -_                  _.-(`-.____.'// \
          `-._            `---.________.---'    >\      /<   \
              \_             `--.___            \ \-__-/ /    \
                \_                  `----._______\ \  / /__    \
                  \                      /  |,-------'-'\  `-.__\
                   \                    (   ||            \      )
                    `\                   \  ||            /\    /
                      \                   >-||  @)    @) /\    /
                      \                  ((_||           \ \_.'|
                       \                    ||            `-'  |
                       \                    ||             /   |
                        \                   ||            (   '|
                        \                   ||  @)     @)  \   |
                         \                  ||              \  )
                          `\_               `|__         ____\ |
                             \_               | ``----'''     \|
                               \_              \    .--___    |)
                                 `-.__          \   |     \   |
                                      `----.___  \^/|      \/\|
                                               `--\ \-._  / | |  
                                                   \ \  `'  \ \
                                            __...--'  )     (  `-._
                                           (_        /       `.    `-.__
                                             `--.__.'          `.       )
                                                                 `.__.-'


                                     :=+*+-                     
                                  =*+**#%###+:                  
                               =*##*+-    *#**#=                   
                             =*%#+-        -*%%#+                 
                           :##*:              -*#+-                
                            -*#-                 ###=                
                               -                 +**#=              
                                                 +**#=           
                                                 *%%#:          
                                                 =+***          
                                               :=+##*+:         
                                            -=*##**#*:         
                                         =*##%###%%#=         
                                       :=#######%@%%#:        
                                     -=##*##%#%%%%%+++++-:     
                                   :*#**##%###%%%##*#:.:-=++-  
                               -=+++=*#####%%@%#%@%#*-..=   .=:
                            -===-*#####%%%@@@%+###*-:  :=-     
                      :-=+====-::-%%%%%%%*++++*#+++++==--=+-:: 
                   -++++=--=++##*###+******++%%%*+=-::         
                -+**+=            -++**++*==--:.=-             
              +%#+----::      :::.:---:+**    +::             
              +#=-                  :=++*=    -               
              =                      =+#%%#==-                  
                                       -+#==:                   
                                    ===-:                       


 _     _                _          _        _     _                          
| |   (_)_________   _ ( )___     / \   ___(_) __| |                         
| |   | |_  /_  / | | ||// __|   / _ \ / __| |/ _` |                         
| |___| |/ / / /| |_| |  \__ \  / ___ \ (__| | (_| |                         
|_____|_/___/___|\__, |  |___/ /_/   \_\___|_|\__,_|_         _   _          
   / \   __| |_  |___/_ _ __ | |_ _   _ _ __ ___  (_)_ __   | |_| |__   ___ 
  / _ \ / _` \ \ / / _ \ '_ \| __| | | | '__/ _ \ | | '_ \  | __| '_ \ / _ \
 / ___ \ (_| |\ V /  __/ | | | |_| |_| | | |  __/ | | | | | | |_| | | |  __/
/_/   \_\__,_| \_/ \___|_| |_|\__|\__,_|_|  \___| |_|_| |_|  \__|_| |_|\___|
▄▄▌ ▐ ▄▌▪  ▄▄▌  ·▄▄▄▄      ▄▄▌ ▐ ▄▌▄▄▄ ..▄▄ · ▄▄▄▄▄
██· █▌▐███ ██•  ██▪ ██     ██· █▌▐█▀▄.▀·▐█ ▀. •██  
██▪▐█▐▐▌▐█·██▪  ▐█· ▐█▌    ██▪▐█▐▐▌▐▀▀▪▄▄▀▀▀█▄ ▐█.▪
▐█▌██▐█▌▐█▌▐█▌▐▌██. ██     ▐█▌██▐█▌▐█▄▄▌▐█▄▪▐█ ▐█▌·
 ▀▀▀▀ ▀▪▀▀▀.▀▀▀ ▀▀▀▀▀•      ▀▀▀▀ ▀▪ ▀▀▀  ▀▀▀▀  ▀▀▀    

                                                                                    
                 :-==++++++++++--:                                                              
               =##*+============+###*=                                                          
             :++:::--==+*###*#*+-::.-+*-                                                        
             **.......................=*-                                                       
            =#:........................=#=                                                      
            #+#..........................-*+-=+#########+-:                                     
         :::#*-:..........................+#+...........-+#-                                    
      -*##*++%*===-:.............................:+*:                                          
    :+*:.....=---------...............................:-+#+                                     
     -*+=-.....................................:--=+###+-                                      
       :=+*##+=======------==============++*#%%#++=-                                           
           =#+++**********************++++==*=                                                 
          -#=================================+*=-:                               --+-           
          -#---=====================-------------==+*+                          -+---#:         
          -#......::::::.............................+=                      -+=-:==-              
          -#:........................................-#                 =+*+-.-+=:                
           +=.........................................#-             -*+=-.==*=                   
            *-...............................:::---=--+-           -*-:=---..*:                    
           =##-.......................................+=          +#+=+=*-*--##+                  
           =+.:=+#####################+-............=#+          +#+=+=*-*--##+                   
            +#+---::...................=*-..::-+#*=-             =+-*##+-..+=                     
           -######******++++========--:..:=+###*=:               .:+=....:*-                       
         *+=------------====++*###*##*#**+:--.:==               ..==......*=                       
        *-.................................:=:.-+-.          :==+#+:......-#                      
       =+...................................:--.:++-.     --++-..:-=++=--++                        
       *=.....................................--..:++-==++=-..........:=#-



                                                ..:::---::
                                            .:=*#+--------*=
                                          :*+--------+*----=+
                                          *------**+=-------#:
                                         =+-----=-----------+-
                                         +--------------------.
                                     -=+#*-------------------#----------=+*##=.
                             :=##+=------+-------------------++----------------*-
                          -#+-----------=+--------------------=----------------=*
                       :++--------------==------------------------------------#-
                      +=---------------------------------------------------=#*
                      #+------------------------------------------------=#*===+#=
                       -#%#+----------------------------------------*#*+=========#*
                            =#%#+----------------------------=+##=....-#===========+#:
                                --+*####%%%%%%%%%%%%%%%%%%%%%+..........+#==========**
                                         -##+-=#%%%%#=-#=#%%%%%%%=.........+*==========+#:
                                         =#%%##%%%%%%##%%%%%%%++%=..........:#===========#=
                                        -+.*=-=++++++++++=-  -+...............*+==========+*
                                        *-..*-               +=................=*===========#:
                                        #....#               #..................-#===========#
                                        #.....%-             +....................++=========+#
                                       #%:.....-*           #:.....................-#==========#
                                       #-=*#=:...-#=:....:++.........................#=========#=
                                       #-===--=*#=-....::.............................#=========#-
                                       #==+---===--=*#=:...............................#========+##+-
                                      -#+==---===-----=-+#+=............................#===+#+=----+
                                      +.#+=---===----===-----+=**+=:....................-##=-======-=+
                                     -+..+=---===----===----===------===*###*=:.......=#=------======#:
                                     #....%*#--------===----==+-----==-----===------%+=====----------+-
                                    -=...:##..-#+-----------===-----===----===---=#---=============--=-
                                    #:...#.#:.....-*#+=-----===-----===----===-#+------------=======+#
                                   :#...*-.-=...........=+#*==------==------+#-====---------------+*-#
                  .:=+=:           --..*-  -#-.................-=+#++=---=#+---==========---====#=---#
                .=%%%%%%%=.....+*+=-.:*    +=#:.......................:+#=-----------=+======*#------*:
              .*%%#=%%%%%%#-#=:......#:  :#..%-...................=**-========------------#*======**-
          .:#%%%++%%%%%%%%%=......-#-    .#:...#=.............:##+---------==============#-..-#====*=
      -%%%#=#%%%%%%+.=%%%%%%+#:          -*...%:.-+:=##---------============-------=#:.......-#==+#
   :=%%#=#%%%%%%*:   -+%%%%%*            =*..==.-#+===---------------============#==#+++*+:..-*==#
  *%%%+%%%%%%#-        +#%%%=            =-..#  *--==========----------------=#+..*.......#..-##-
  #%%%%%%%%+                             =..+:  #-------===========--------+*-...+-.......*.=#-
     #%#=:                              =#:-=   =-------------========-+#=:......+=......=#=.
                                     =#-..+#    :#====-------------*#=:.......:-=++......#.
                                  +*-..-#-       #=======------#*-..::::::::.----.#.....-+
                                 #..-+*.          ++---===##%-                    *:....*=
                                +-..#                 #.....#:                    +=...:#
                                #:.*:                 *:...-#                     -*...-=
                                #::#                  ++...+:                     :*...*:
                                -+*#:                 ++...#                      .#..:#
                                                      -+..=+                      .#..=*
                                                       +..+-                      :*:=#-
                                                      =+.+%                       :*.-##
                                                      =+.*#=                      .+#:.:#
                                                       #=..-*                     .--....*:
                                                       =....:*                    ..#:...-%*-
                                                       :#....+##                   =#+*+=--*.
                                                       :+#*+=---=                    +------=+
                                                        -=------*-                   +=------*
                                                         #-------+                    *------=-
                                                          +------*                   =#=-----=*
                                                         **------+-                 #=-------+:
                                                       -#--------*                 +--------*:
                                                       *-------=+                  -*++===*=
                                                       =*++==+*:

ant

 \  \  
 |__/ _   .-.
(o_o)(_`>(   )
 { }//||\\`-'

Caterpillar
                           .    .
                            )  (
      _ _ _ _ _ _ _ _ _ _ _(.--.)
    {{ { { { { { { { { { { ( '_')
     >>>>>>>>>>>>>>>>>>>>>>>`--'>

Roach

  ,--.       ,---. 
  /    '.    /     \ 
         \  ; 
          \-| 
         (o o)      (/ 
         /'v'     ,-' 
 ,------/ >< \---' 
/)     ;  --  : 
   ,---| ---- |--. 
  ;    | ---- |   : 
 (|  ,-| ---- |-. |) 
    | /| ---- |\ | 
    |/ | ---- | \| 
    \  : ---- ;  | 
     \  \ -- /  / 
     ;   \  /  : 
    /   / \/ \  \ 
   /)           (\

Snail

     /^\    /^\
    {  O}  {  O}
     \ /    \ /
     //     //       _------_
    //     //     ./~        ~-_
   / ~----~/     /              \
 /         :   ./       _---_    ~-
|  \________) :       /~     ~\   |
|        /    |      |  :~~\  |   |
|       |     |      |  \___-~    |
|        \ __/`^\______\.        ./
 \                     ~-______-~\.
 .|                                ~-_
/_____________________________________~~____

Worm

                                                /~~\
  ____                                         /'o  |
.~  | `\             ,-~~~\~-_               ,'  _/'|
`\_/   /'\         /'`\    \  ~,             |     .'
    `,/'  |      ,'_   |   |   |`\          ,'~~\  |
     |   /`:     |  `\ /~~~~\ /   |        ,'    `.'
     | /'  |     |   ,'      `\  /`|      /'\    /
     `|   / \_ _/ `\ |         |'   `----\   |  /'
      `./'  | ~ |   ,'         |    |     |  |/'
       `\   |   /  ,'           `\ /      |/~'
         `\/_ /~ _/               `~------'
             ~~~~

https://www.asciiart.eu/image-to-ascii
@@@@@@@@@@%                                                     -@@@@@@@@@@
@@@@@@@@@@%                                                     -@@@@@@@@@@
@@@@@@@@@@%                                                     -@@@@@@@@@@
@@@@@@@@@@%                    #%#%*%##%+                       -@@@@@@@@@@
@@@@@@@@@@%                 .##**********%*                     -@@@@@@@@@@
@@@@@@@@@@%                 +#*************@.                   -@@@@@@@@@@
@@@@@@@@@@%                .@**************%.                   -@@@@@@@@@@
@@@@@@@@@@%    .#####%%%%###@@#*++=========++++*%%%%%#==%.      -@@@@@@@@@@
@@@@@@@@@@%    :*+---------------------------------=**:         -@@@@@@@@@@
@@@@@@@@@@%      ..::-+***%%@@%%%%%%%%%%%%%@**+-:...            -@@@@@@@@@@
@@@@@@@@@@%                 %#+++++++++++++@.                   -@@@@@@@@@@
@@@@@@@@@@%                 %%+++++++++++++@.                   -@@@@@@@@@@
@@@@@@@@@@%                 #%.....:..... .@.                   -@@@@@@@@@@
@@@@@@@@@@%                 +@            .@.                   -@@@@@@@@@@
@@@@@@@@@@%                 :@#@##.   --*%@@.                   -@@@@@@@@@@
@@@@@@@@@@%                .+@.  *.   .*  :@.                   -@@@@@@@@@@
@@@@@@@@@@%             .-+++@ ..*.   -: ..@++=:.               -@@@@@@@@@@
@@@@@@@@@@%          .+++++++@+. %@@@@@: .#@+++++++.            -@@@@@@@@@@
@@@@@@@@@@%          =++++++++@*:#+#+*%:-#@++++++++++           -@@@@@@@@@@
@@@@@@@@@@%         .++++++++++%@%++%**@@*+++++++++++-          -@@@@@@@@@@
@@@@@@@@@@%         =++++++++++++++#*+++++++++++++++++          -@@@@@@@@@@
@@@@@@@@@@%        .++++++++++++++#+++++++++++++++++++.         -@@@@@@@@@@
@@@@@@@@@@%        :+++++*+++++++#++++++++++++#+++++++=         -@@@@@@@@@@
@@@@@@@@@@% .@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@- -@@@@@@@@@@
@@@@@@@@@@% .#  SHERIFF ROACH:                               +- -@@@@@@@@@@
@@@@@@@@@@% .#                                               +- -@@@@@@@@@@
@@@@@@@@@@% .#   You better not cause trouble round here...  +- -@@@@@@@@@@
@@@@@@@@@@% .#                                               +- -@@@@@@@@@@
@@@@@@@@@@% .-------------------------------------------------. -@@@@@@@@@@

@@@@@@@@@@%                                                     -@@@@@@@@@@
@@@@@@@@@@%                                                     -@@@@@@@@@@
@@@@@@@@@@%                                                     -@@@@@@@@@@
@@@@@@@@@@@:.                                                   -@@@@@@@@@@
@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@.           .:::.        -@@@@@@@@@@
@@@@@@@@@@@+++++++++********++*****+*@%      ..   =+====.    .. -@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%###@%    .@@@#  =+====.  =@%@%-@@@@@@@@@@
@@@@@@@@@@@======+++++++++**####%@#*#@%  .@-@.=@= .#===%. #@- .@@@@@@@@@@@@
@@@@@@@@@@@=====================#@*+*@@   -*:  #@=%@%%@@@%@:  :*=@@@@@@@@@@
@@@@@@@@@@@=====================%@++*@@       .%@@%#++===-#@#. .-@@@@@@@@@@
@@@@@@@@@@@=====================%@*+*@@      =@*==.       :.@*  -@@@@@@@@@@
@@@@@@@@@@@-----------==========%@*+*@@      %@#-%*+    %=@=@#  -@@@@@@@@@@
@@@@@@@@@@@----------------=====%@*+*@@.     -@@*#-*.  =-+#*@%  -@@@@@@@@@@
@@@@@@@@@@@-----------------====%@*++@@-     .@--@@+   .#@+:@+  -@@@@@@@@@@
@@@@@@@@@@@-------------------==@@*++@@+      %%           #@:  -@@@@@@@@@@
@@@@@@@@@@@---------------------@@*++@@#      *@=         +@+   -@@@@@@@@@@
@@@@@@@@@@@---------------------%@*++%@#       *@+.      #@@.   -@@@@@@@@@@
@@@@@@@@@@@---------------------#@*++%@#      .%=@@@@@@@@@===@: -@@@@@@@@@@
@@@@@@@@@@@---------------------=@#++%@%     .%===+#*...#=====+%+@@@@@@@@@@
@@@@@@@@@@@----------------------@%++%@%    =#=======*#@========*@@@@@@@@@@
@@@@@@@@@@@----------------------@@++#@%  .%+=========+%=====#+=*@@@@@@@@@@
@@@@@@@@@@@----------------------@@++#@%  .@===========@======+@*@@@@@@@@@@
@@@@@@@@@@@----------------------%@++#@%  .@===%=======@======#=*@@@@@@@@@@
@@@@@@@@@@@----------------------*@*+#@%  .@===%+======@#=====*@#@@@@@@@@@@
@@@@@@@@@@@----------------------+@#+#@%  .@===%+======@-+=====#*@@@@@@@@@@
@@@@@@@@@@@-----------------------@%+*@@. .@===%+=+====@.*+=====%@@@@@@@@@@
@@@@@@@@@@@-----------------------@@++@@: .@===%+=@====@. +*====*@@@@@@@@@@
@@@@@@@@@@@-----------------------%@++%@+ .@===%+=@*===@.  .%+==*@@@@@@@@@@
@@@@@@@@@@@-----------------------#@*+*@% .@===%++@*===@%@@@@@%+*@@@@@@@@@@
*/