#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <thread>
#include <Windows.Threading>

//#Using RecoilMAIN
//#Using Data
// Delete this or replace it, idc.

struct color_t { DWORD r, g, b; }; 
// Fix errors self, filthy animal 
// credit to Zeway for talking about this on uc:)

 int padding = 71;

struct vec2_t
{
    int x, y;
 
    vec2_t operator-(vec2_t input)
    {
        return { x - input.x, y - input.y };
    }
};
//Break just to avoid some stupid errors:)

enum WEAPONS
{
    WEAPON_AK,
    WEAPON_LR,
    WEAPON_MP5,
    WEAPON_TOMMY,
    WEAPON_SEMI,
    WEAPON_M92,
    WEAPON_SMG,
    WEAPON_PYTHON,
    WEAPON_M39,
    WEAPON_M249,
    WEAPON_EOKA,
    WEAPON_NONE
};

    struct copos_t {
    color_t color;
    vec2_t position;
};
                                                              // fix urself


struct weapon_t {
    std::vector< copos_t > cospos; WEAPONS weapon; const char* name;
    weapon_t(std::vector< copos_t> _cospos, WEAPONS _weapon, const char* _name)
    {
        cospos = _cospos;
        weapon = _weapon;
        name = _name;
    }
};

float compare_color ( color_t source, color_t target )
{
    float r = std::abs ( ( float )source.r - ( float )target.r );
    float g = std::abs ( ( float )source.g - ( float )target.g );
    float b = std::abs ( ( float )source.b - ( float )target.b );
    return 100.f - ( ( r + g + b ) * 100.f ) / ( 255.f * 3.f );
}

// only works for hotbar slot number 1 unless changed :) 
vec2_t hotbar_position = { 740, 1058 };
second_slot_position.x - first_slot_position.x
// shouts to zeway once again



    struct globals_t
{
    vec2_t hotbar_position = { 740, 1058 };
    vec2_t selection_position = { -8, 5 };
    int padding = 71;
}globals;

// errors = doo doo 

     int get_selected_slot ( )
{
    std::vector<slot_t> slots = {};
    for ( int i = 0; i < 6; i++ )
    {
        vec2_t position = globals.hotbar_position - globals.selection_position;
        position.x += globals.padding * i;
        color_t color = get_pixel_color ( position.x, position.y );
        float percent = compare_color ( { 77, 113, 149 }, color );
        slots.push_back ( { percent, i } );
    }
    slot_t ret_slot = { 76.5f, -1 };
    for ( auto &slot : slots )
    {
        if ( slot.percent > ret_slot.percent )
        {
            ret_slot.percent = slot.percent;
            ret_slot.index = slot.index;
        }
    }
    return ret_slot.index;
}




weapon_t get_weapon_by_id ( WEAPONS weapon_id )
{
    if ( weapon_id == WEAPON_NONE )
        return weapon_t ( {}, WEAPON_NONE, "" );
 
    for ( auto &weapon : weapons )
    {
        if ( weapon.weapon == weapon_id )
        {
            return weapon;
        }
 
    }
 
 
 
 
    return weapon_t ( {}, WEAPON_NONE, "" );
}





// final bit of coding



weapon_t get_weapon ( )
{
    int selected_slot = get_selected_slot ( );
 
    if ( selected_slot == -1 )
    {
        return get_weapon_by_id ( WEAPON_NONE );
    }
 
    std::vector<weapon_color_t> weapons_color = {};
    for ( auto &weapon : weapons )
    {
        float percent = 0.f;
        for ( int i = 0; i < weapon.cospos.size ( ); i++ )
        {
            vec2_t position = globals.hotbar_position - weapon.cospos[i].position;
            position.x += globals.padding * selected_slot;
            color_t color = get_pixel_color ( position.x, position.y );
            percent += compare_color ( color, weapon.cospos[i].color ) / weapon.cospos.size ( );
        }
        weapons_color.push_back ( { percent, weapon.weapon } );
 
    }
 
    weapon_color_t ret_weapon = { 83.5f, WEAPON_NONE };
    for ( auto &weapon : weapons_color )
    {
        if ( weapon.percent > ret_weapon.percent )
        {
            ret_weapon.percent = weapon.percent;
            ret_weapon.weapon = weapon.weapon;
        }
 
    }
 
    return get_weapon_by_id ( ret_weapon.weapon );
}
