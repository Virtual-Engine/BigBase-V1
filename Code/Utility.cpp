#include "Common.hpp"
#include "ImGui/imgui.h"
#include "Translation.hpp"

using namespace Big;

NativeVector3 Utilityy::RotationToDirectionV3(NativeVector3 rot) {
	NativeVector3 dir;
	float radiansZ = rot.z * 0.0174532924f;
	float radiansX = rot.x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}

NativeVector3 Utilityy::AddV3(NativeVector3 vectorA, NativeVector3 vectorB) {
	NativeVector3 result;
	result.x = vectorA.x;
	result.y = vectorA.y;
	result.z = vectorA.z;
	result.x += vectorB.x;
	result.y += vectorB.y;
	result.z += vectorB.z;
	return result;
}

NativeVector3 Utilityy::MultiplyV3(NativeVector3 vector, float x) {
	NativeVector3 result;
	result.x = vector.x;
	result.y = vector.y;
	result.z = vector.z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

float Utilityy::GetDistanceFloat(NativeVector3 pointA, NativeVector3 pointB) {
	float a_x = pointA.x;
	float a_y = pointA.y;
	float a_z = pointA.z;
	float b_x = pointB.x;
	float b_y = pointB.y;
	float b_z = pointB.z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

float Utilityy::GetVectorLengthFloat(NativeVector3* vector) {
	double x = (double)vector->x;
	double y = (double)vector->y;
	double z = (double)vector->z;
	return(float)sqrt(x * x + y * y + z * z);
}


NativeVector3 Utilityy::GetBlipIcon()
{
	static NativeVector3 zero;
	NativeVector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = HUD::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = HUD::GET_FIRST_BLIP_INFO_ID(blipIterator); HUD::DOES_BLIP_EXIST(i) != 0; i = HUD::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (HUD::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = HUD::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}

	return zero;
}

void Utilityy::WriteFlameFlag(uint32_t Flag)
{

	uint32_t CurrentValue = Memory::get_value<uint32_t>({ 0x8, 0x10A8, 0x270 });
	Memory::set_value<uint32_t>({ 0x8, 0x10A8, 0x270 }, CurrentValue |= Flag);

}

void Utilityy::RemoveFlameFlag(uint32_t Flag)
{

	uint32_t CurrentValue = Memory::get_value<uint32_t>({ 0x8, 0x10A8, 0x270 });
	Memory::set_value<uint32_t>({ 0x8, 0x10A8, 0x270 }, CurrentValue &= ~(1 << Flag));
}

const char* draw_keyboard() {
	MISC::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0) {

	}
	if (!MISC::GET_ONSCREEN_KEYBOARD_RESULT()) {
		return 0;
	}
	return MISC::GET_ONSCREEN_KEYBOARD_RESULT();
}
void notifyMap(int notifyColor, const char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	HUD::SET_TEXT_OUTLINE();
	HUD::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	HUD::_SET_NOTIFICATION_BACKGROUND_COLOR(notifyColor);
	HUD::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("Virtual_X_T", (char*)"notify", true, 5, (char*)"~p~Virtual X", (char*)"", 1.f, (char*)"", 5, 0);
}	void notifyMap(std::string str) { notifyMap(&str[0]); }

void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
	{
		RequestControlOfEnt(e);
	}

	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);

}
enum ScaleformButtons { ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, BUTTON_DPAD_UP, BUTTON_DPAD_DOWN, BUTTON_DPAD_RIGHT, BUTTON_DPAD_LEFT, BUTTON_DPAD_BLANK, BUTTON_DPAD_ALL, BUTTON_DPAD_UP_DOWN, BUTTON_DPAD_LEFT_RIGHT, BUTTON_LSTICK_UP, BUTTON_LSTICK_DOWN, BUTTON_LSTICK_LEFT, BUTTON_LSTICK_RIGHT, BUTTON_LSTICK, BUTTON_LSTICK_ALL, BUTTON_LSTICK_UP_DOWN, BUTTON_LSTICK_LEFT_RIGHT, BUTTON_LSTICK_ROTATE, BUTTON_RSTICK_UP, BUTTON_RSTICK_DOWN, BUTTON_RSTICK_LEFT, BUTTON_RSTICK_RIGHT, BUTTON_RSTICK, BUTTON_RSTICK_ALL, BUTTON_RSTICK_UP_DOWN, BUTTON_RSTICK_LEFT_RIGHT, BUTTON_RSTICK_ROTATE, BUTTON_A, BUTTON_B, BUTTON_X, BUTTON_Y, BUTTON_LB, BUTTON_LT, BUTTON_RB, BUTTON_RT, BUTTON_START, BUTTON_BACK, RED_BOX, RED_BOX_1, RED_BOX_2, RED_BOX_3, LOADING_HALF_CIRCLE_LEFT, ARROW_UP_DOWN, ARROW_LEFT_RIGHT, ARROW_ALL, LOADING_HALF_CIRCLE_LEFT_2, SAVE_HALF_CIRCLE_LEFT, LOADING_HALF_CIRCLE_RIGHT, };
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}
int m_offset;
bool m_prepared;
int m_scaleForm;
int duration;
void WelcomeScreen(bool enable)
{
	if (enable)
	{

		int m_scaleForm = GRAPHICS::REQUEST_SCALEFORM_MOVIE("mp_big_message_freemode");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "SHOW_SHARD_WASTED_MP_MESSAGE");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_STRING(u8"~p~∑ ~b~Virtual X ~p~∑");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_STRING("Welcome to ~b~Virtual X ~p~1.9X1");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(5);
		GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
		GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(m_scaleForm, 255, 255, 255, 255, 0);
		GRAPHICS::REQUEST_SCALEFORM_MOVIE("INSTRUCTIONAL_BUTTONS");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "SET_DATA_SLOT");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_STRING("t_C");
		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_STRING("Stop preview");
		GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();


	}
}
void PrepareInstructionalButtons(bool enable) {
	if (enable)
	{
		m_scaleForm = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
		if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(m_scaleForm)) {
			GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(m_scaleForm, 255, 255, 255, 0, 0);
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "CLEAR_ALL");
			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "SET_CLEAR_SPACE");
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(200);
			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "SET_MAX_WIDTH");
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(1);
			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "SET_DATA_SLOT_EMPTY");
			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
		}
		m_prepared = true;
	}
}
void FinishInstructionalButtons(bool enable) {

	if (enable)
	{
		if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(m_scaleForm)) {
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "DRAW_INSTRUCTIONAL_BUTTONS");
			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(m_scaleForm, "SET_BACKGROUND_COLOUR");
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(/*GetRenderer()->m_cOutline.m_r*/ 0);
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(/*GetRenderer()->m_cOutline.m_g*/ 0);
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(/*GetRenderer()->m_cOutline.m_b*/ 0);
			GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(80);
			GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			m_offset = 0;
		}
	}
	m_prepared = false;
}

void set_text_component(const char* text)
{
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
	HUD::_ADD_TEXT_COMPONENT_SCALEFORM(text);
	GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();

}
void instructionalSetup() {


	int movie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(movie, 255, 255, 255, 0, 0);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "CLEAR_ALL");
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "SET_CLEAR_SPACE");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(200);
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();

}
void addInstructional(const char* text, int button, int instructCount) {

	int movie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "SET_DATA_SLOT");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(instructCount);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(button);   set_text_component(text);
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}
void instructionalClose() {
	int movie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(80);
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}


void low_graphics(bool toggle)
{
	if (toggle)
	{
		NativeVector3 me = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		STREAMING::_SET_FOCUS_AREA(me.x, me.y, me.z - 2000, me.x, me.y, me.z - 2000);
	}
}

void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}


int32_t bc = 0;
int32_t handle = 0;

void setup() {
	handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(handle, 255, 255, 255, 255, 0);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(handle, "CLEAR_ALL");
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();

	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(handle, "SET_CLEAR_SPACE");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(200);
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}
void text_component(char* text) {
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)text);
	GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
}
void add(char* text, int button) {
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(handle, "SET_DATA_SLOT");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(bc);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(button);
	text_component(text);
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	bc++;
}
void add(char* text, char* button) {
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(handle, "SET_DATA_SLOT");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(bc);
	text_component(button);
	text_component(text);
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	bc++;
}
void draw() {
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(handle, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(handle, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);  // R
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);  // G
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);  // B
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(80); // A
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	bc = 0;
}


void UtilityUpdateLoop()
{

	WelcomeScreen(g_Utility->openedYet);
	PrepareInstructionalButtons(g_Utility->openedYet);
	FinishInstructionalButtons(g_Utility->openedYet);
	//addInstructional("Open Submenu", BUTTON_A, 0);
	//addInstructional("Exit Menu", BUTTON_B, 1);
	//addInstructional("Scroll", BUTTON_DPAD_UP_DOWN, 2);
	//instructionalSetup(g_Utility->openedYet);
	instructionalClose();
	low_graphics(g_Utility->g_low_graphics);
}

script_global::script_global(std::size_t index) :
	m_index(index)
{
}

script_global script_global::at(std::ptrdiff_t index)
{
	return script_global(m_index + index);
}

script_global script_global::at(std::ptrdiff_t index, std::size_t size)
{
	return script_global(m_index + 1 + (index * size));
}

void* script_global::get()
{
	return g_GameFunctions->m_ScriptGlobals[m_index >> 0x12 & 0x3F] + (m_index & 0x3FFFF);
}