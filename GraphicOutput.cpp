#include "GraphicOutput.h"


void graphic_init()
{
    SDL_SetHint(SDL_HINT_IME_SHOW_UI,"1");
    TTF_Init();
}

/************************************************-----function-----************************************************/

RectButton::RectButton()
{
    ;
}

RectButton::RectButton(SDL_Rect& rect,SDL_Color& border_color,SDL_Color& fill_color,int font_size,SDL_Color& font_color,const char* text)
{
    this->rect=rect;
    this->font_size=font_size;
    this->font_color=font_color;
    this->fill_color=fill_color;
    this->border_color=border_color;
    
    if(text!=NULL)
        strcpy(this->text,text);
    else
        strcpy(this->text,"");

    this->text_rect=rect;
    this->text_rect.x+=5;
    this->text_rect.y+=5;
}

void RectButton::SetValue(SDL_Rect& rect,SDL_Color& border_color,SDL_Color& fill_color,int font_size,SDL_Color& font_color,const char* text)
{
    this->rect=rect;
    this->font_size=font_size;
    this->font_color=font_color;
    this->fill_color=fill_color;
    this->border_color=border_color;
    
    if(text!=NULL)
        strcpy(this->text,text);
    else
        strcpy(this->text,"");

    this->text_rect=rect;
    this->text_rect.x+=5;
    this->text_rect.y+=5;
}

void RectButton::Draw(SDL_Renderer* rdr)
{
    
    SDL_SetRenderDrawColor(rdr,this->fill_color.r,this->fill_color.g,this->fill_color.b,this->fill_color.a);
    SDL_RenderFillRect(rdr,&(this->rect));

    SDL_SetRenderDrawColor(rdr,this->border_color.r,this->border_color.g,this->border_color.b,this->border_color.a);
    SDL_RenderDrawRect(rdr,&(this->rect));

    if(strcmp(this->text,""))
    {   
        /*
            notice:
            program file in bin
            current terminal -> ./
            exe file -> ../
        */
        TTF_Font* font=TTF_OpenFont("../resource/font/simkai.ttf",font_size);
        if(font==NULL)
        {
            SDL_Log("TTF_OpenFont:%s",TTF_GetError());
            return;
        }

        SDL_Surface* text_surf=TTF_RenderUTF8_Blended(font,text,this->font_color);
        SDL_Texture* text_tt=SDL_CreateTextureFromSurface(rdr,text_surf);
        this->text_rect.w=text_surf->w,this->text_rect.h=text_surf->h;
        this->text_rect.x=this->rect.x+5,this->text_rect.y=this->rect.y+5;
        SDL_RenderCopy(rdr,text_tt,NULL,&(this->text_rect));

        TTF_CloseFont(font);
        SDL_FreeSurface(text_surf);
        SDL_DestroyTexture(text_tt);
    }
}

void RectButton::InteractResponse_green(SDL_Point& pt,SDL_Rect& rect)
{
    if(SDL_PointInRect(&pt,&rect))
    {
        this->fill_color.r=0;
        this->fill_color.g=220;
        this->fill_color.b=0;
    }
    else
    {
        this->fill_color.r=255;
        this->fill_color.g=255;
        this->fill_color.b=255;
    }
}

void RectButton::InteractResponse_red(SDL_Point& pt,SDL_Rect& rect)
{
    if(SDL_PointInRect(&pt,&rect))
    {
        this->fill_color.r=220;
        this->fill_color.g=0;
        this->fill_color.b=0;
    }
    else
    {
        this->fill_color.r=255;
        this->fill_color.g=255;
        this->fill_color.b=255;
    }
}

RectButton::~RectButton()
{
    ;
}

/************************************************-----function-----************************************************/

Text::Text(int x,int y,SDL_Color& font_color,int font_size,const char* text)
{
    this->text_rect.x=x;
    this->text_rect.y=y;
    this->font_color=font_color;
    this->font_size=font_size;

    if(text!=NULL)
        strcpy(this->text,text);
    else
        strcpy(this->text,"");
}

void Text::Draw(SDL_Renderer* rdr)
{
    if(strcmp(this->text,""))
    {   
        /*
            notice:
            program file in bin
            current terminal -> ./
            exe file -> ../
        */
        TTF_Font* font=TTF_OpenFont("../resource/font/simkai.ttf",font_size);
        if(font==NULL)
        {
            SDL_Log("TTF_OpenFont:%s",TTF_GetError());
            return;
        }

        SDL_Surface* text_surf=TTF_RenderUTF8_Blended(font,text,this->font_color);
        SDL_Texture* text_tt=SDL_CreateTextureFromSurface(rdr,text_surf);
        this->text_rect.w=text_surf->w,this->text_rect.h=text_surf->h;
        SDL_RenderCopy(rdr,text_tt,NULL,&(this->text_rect));

        TTF_CloseFont(font);
        SDL_FreeSurface(text_surf);
        SDL_DestroyTexture(text_tt);
    }
}

Text::~Text()
{
    ;
}

/************************************************-----function-----************************************************/