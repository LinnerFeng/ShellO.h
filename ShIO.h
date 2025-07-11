#ifndef _SHIO_H_
#define _SHIO_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
**
**此结构体用于鼠标事件的
**处理方式。而这个一般用于
**处理按钮事件。
**
*/

typedef struct{
    int type;
    int x;
    int y;
}KeyEvent;

/*
**
**当然，在没鼠标的情况下
**(如FreeBSD)，则使用"
**up","down"来控制控件，
**而这个结构体正是这么实
**现的。
**
*/

typedef struct{
    int evnt;
}KeyBoardEvent;

/*
**
**按钮等基本控件的主类
**当调用实则使用此类。
**
*/

typedef struct {
    int x;
    int y;
    unsigned char fg;
    unsigned char bg;
} BasicWidgetClass;


/*
**
**这个是用于输入模式的枚举,
**而在下面的一个则是对于输入
**内容的枚举
**
*/

typedef enum{
    INPUT_MODE_NORMAL,
    INPUT_MODE_SECRET,
    INPUT_MODE_HIDE
}InputMode;


typedef enum{
    TYPE_INT,
    TYPE_CHAR,
    TYPE_UINT,
    TYPE_FLOAT
}BufferType;


/*
**
**ANSI转义码过于麻烦
**接下来的相关宏和函
**数为ANSI读取，为后面
**的函数提供提供帮助。
**
*/


typedef enum {
    RESET,
    BOLD,
    ITALIC,
    GRAY,
    UNDERLINE,
    OVERLINE,
    DISAPERD,
    BLINK,
    REVERSIVE,
    DOUBLEUNDERLINE,
    UPPERLINE,
    HIGHLIGHT
}ANSICodeStyle;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
}ANSICodeCursorControl;

typedef enum {
    BG_BLACK,
    BG_RED,
    BG_GREEN,
    BG_YELLOW,
    BG_BLUE,
    BG_PURPLE,
    BG_CYAN,
    BG_WHITE
}ANSICodeBasicColorBackGround;

typedef enum {
    FG_BLACK,
    FG_RED,
    FG_GREEN,
    FG_YELLOW,
    FG_BLUE,
    FG_PURPLE,
    FG_CYAN,
    FG_WHITE
}ANSICodeBasicColorForeGround;

typedef enum{
    REAL,
    BASIC,
    TYPE256
}ANSICodeSetting;

typedef struct{
    int r;
    int g;
    int b;
}ANSICodeRealColor;



/*
**
**接下来是最最基本的几个函数，
**分别为开始函数和结束的函数。
**这个便是开始的，用于清屏。
**
*/

inline void ClearScreen(){
    #ifdef _WIN32
    system("cls");
    printf("\033[?25l");
    #elif defined(__LINUX__)||defined(__UNIX__)
    system("clear");
    printf("\033[?25l");
    #else
    #error "Invalid OS !!!!!"
    #endif
};


inline int EndPro(){
    return 0;
};


/*
**
**主要的变量，分别为：
**  输入框的替代文本；
**  光标样式；
**  进度条样式；
**  窗口样式设定。
**
*/


#define TEXT_SHOW_TYPE_STAR   " * "
#define TEXT_SHOW_TYPE_SHARP  " # "
#define TEXT_SHOW_TYPE_NONE   "   "
#define TEXT_SHOW_TYPE_SPEC  " ▮ "

#define STYLE_CLASSIC 0xFFFCF0
#define STYLE_LIGHT   0xFFFFFF
#define STYLE_DARK    0x797979


#define CUROSR_TYPE_DEFAULT_SHINING         "\033[5m"
#define CURSOR_TYPE_DEFAULT_NONE            "\033[0m"
#define CURSOR_TYPE_DEFAULT_UNDERLINE       '_'
#define CURSOR_TYPE_DEFAULT_CLASSIC         '▬'
#define CURSOR_TYPE_SQUARE_COLORED_SMALL    '◪'
#define CURSOR_TYPE_SQUARE_COLORED_BIG      '▮'
#define CURSOR_TYPE_SQUARE_NOCOLOR_HORIZON  '▭'
#define CURSOR_TYPE_SQUARE_NOCOLOR_VERTICAL '▯'


#define PROGRESSBAR_STYLE_BAR    '▮'
#define PROGRESSBAR_STYLE_SHARP  '#'
#define PROGRESSBAR_STYLE_DOLLAR '$'


/*
**
**接下来的宏为表格及面板所需的边框类型
**
*/

#define TABEL_DEFAULT_STYLE_LEFT     '┌'
#define TABEL_DEFAULT_STYLE_RHIGHT   '┐'
#define TABEL_DEFAULT_STYLE_VERTICAL '|'
#define TABEL_DEFAULT_STYLE_HORIZON  '-'

#define TABEL_BOLD_STYLE_LEFT        '┌'
#define TABEL_BOLD_STYLE_RHIGHT      '┐'
#define TABEL_DEFAULT_STYLE_VERTICAL '|'
#define TABEL_DEFAULT_STYLE_HORIZON  '-'


/*
**
**接下来定义的几个函数的作用为输入和输出，
**输入返回的值为int,char,uint,long,float
**等值，而且输入功能支持改变颜色处理鼠标控制
**
*/


inline void ShIOPrintf(BasicWidgetClass *Widget,\
     const char *text,\
    ANSICodeSetting setting,\
    ANSICodeStyle style
){

    unsigned char organic_fg=Widget->fg;
    unsigned char organic_bg=Widget->bg;
    
    printf("\033[%d;%dH",Widget->y,Widget->x);

    va_list args;

    char COLORTYPE;

    switch (style) {

        /*
        **
        **TODO:switch the style for the print function
        **
        */
        
        case BOLD:

        printf("\033[1m");
        break;

        case ITALIC:

        printf("\033[3m");
        break;

        case RESET:

        printf("\033[0m");
        break;

        case GRAY:

        printf("\033[2m");
        break;

        case UNDERLINE:

        printf("\033[4m");
        break;

        case OVERLINE:
        printf("\033[9m");
        break;

        case DISAPERD:
        printf("\033[8m");
        break;

        case BLINK:
        printf("\033[5m");
        break;

        case REVERSIVE:
        printf("\033[7m");
        break;

        case DOUBLEUNDERLINE:
        printf("\033[21m");
        break;

        case UPPERLINE:
        printf("\033[53m");
        break;

        case HIGHLIGHT:
        printf("\033[16m");
        break;

        default:
        break;
    };
    
    /*
    **This enum does not work in this time 
    **because it will make more extra option 
    */

    //switch (setting) {
    //
    //case REAL:
    //
    //COLORTYPE=-1;
    //break;
    //
    //case BASIC:
    //
    //COLORTYPE=1;
    //break;
    //
    //case TYPE256:
    //
    //COLORTYPE=0;
    //break;
    //
    //default:
    //  break;
    //};

    /*TODO:set real color*/

    printf("%s \033[%u;%um",text,organic_fg,organic_bg);/*TODO: The core achive*/

};


inline void ShIOProgressBar(const char *format,\
    const char *text,\
    ANSICodeBasicColorBackGround bg,\
    ANSICodeBasicColorForeGround fg,
    ANSICodeStyle style
){

    switch (style) {

        /*
        **
        **TODO:switch the style for the print function
        **
        */
        
        case BOLD:

        printf("\033[1m");
        break;

        case ITALIC:

        printf("\033[3m");
        break;

        case RESET:

        printf("\033[0m");
        break;

        case GRAY:

        printf("\033[2m");
        break;

        case UNDERLINE:

        printf("\033[4m");
        break;

        case OVERLINE:
        printf("\033[9m");
        break;

        case DISAPERD:
        printf("\033[8m");
        break;

        case BLINK:
        printf("\033[5m");
        break;

        case REVERSIVE:
        printf("\033[7m");
        break;

        case DOUBLEUNDERLINE:
        printf("\033[21m");
        break;

        case UPPERLINE:
        printf("\033[53m");
        break;

        case HIGHLIGHT:
        printf("\033[16m");
        break;

        default:
        break;
    };
    

    char buffer[100+1]={0};
    char array[5]={"-/|\\"};

    for (int i=0;i<100;i++){

        buffer[i]=*format;
        printf("[%-100s][%d%%][%c]\r",\
        buffer,i+1,array[i%4]);
        fflush(stdout);
        _sleep(1);

    };
    printf("\n");
};
   


#endif