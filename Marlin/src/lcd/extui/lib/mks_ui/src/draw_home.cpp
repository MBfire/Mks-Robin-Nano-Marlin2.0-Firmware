#include "../../../../../MarlinCore.h"
#if ENABLED(TFT_LITTLE_VGL_UI)
#include "../inc/draw_ready_print.h"
#include "../inc/draw_set.h"
#include "lv_conf.h"
//#include "../../lvgl/src/lv_objx/lv_imgbtn.h"
//#include "../../lvgl/src/lv_objx/lv_img.h"
//#include "../../lvgl/src/lv_core/lv_disp.h"
//#include "../../lvgl/src/lv_core/lv_refr.h"
//#include "../../MarlinCore.h"
#include "../inc/draw_ui.h"
#include "../../../../../gcode/queue.h"

static lv_obj_t * scr;

#define ID_H_ALL			1
#define ID_H_X				2
#define ID_H_Y				3
#define ID_H_Z				4
#define ID_H_RETURN			5
#define ID_H_OFF_ALL		6
#define ID_H_OFF_XY			7

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch(obj->mks_obj_id)
	{
	case ID_H_ALL:
	    if(event == LV_EVENT_CLICKED) {
			
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
	        queue.inject_P(PSTR("G28"));
	    }
		break;
	case ID_H_X:
		if(event == LV_EVENT_CLICKED) {
			
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
	        queue.inject_P(PSTR("G28 X0"));
	    }
		break;
	case ID_H_Y:
		if(event == LV_EVENT_CLICKED) {
			
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
	        queue.inject_P(PSTR("G28 Y0"));
	    }
		break;
	case ID_H_Z:
		if(event == LV_EVENT_CLICKED) {
			
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
	        queue.inject_P(PSTR("G28 Z0"));
	    }
		break;
	case ID_H_OFF_ALL:
		if(event == LV_EVENT_CLICKED) {
			
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
	        queue.inject_P(PSTR("M84"));
	    }
		break;
	case ID_H_OFF_XY:
		if(event == LV_EVENT_CLICKED) {
			
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
	        queue.inject_P(PSTR("M84 X Y"));
	    }
		break;
	case ID_H_RETURN:
	    if(event == LV_EVENT_CLICKED) {
			
	    }
	    else if(event == LV_EVENT_RELEASED) {
			lv_obj_del(scr);
	        	lv_draw_tool();
	    }
		break;

	}
}


void lv_draw_home(void)
{
	lv_obj_t *buttonHomeAll,*buttonHomeX,*buttonHomeY,*buttonHomeZ;
	lv_obj_t *buttonBack;
	lv_obj_t *buttonOffAll,*buttonOffXY;

	if(disp_state_stack._disp_state[disp_state_stack._disp_index] != ZERO_UI)
	{
		disp_state_stack._disp_index++;
		disp_state_stack._disp_state[disp_state_stack._disp_index] = ZERO_UI;
	}
	disp_state = ZERO_UI;

	scr = lv_obj_create(NULL, NULL);

	//static lv_style_t tool_style;
	
	lv_obj_set_style(scr, &tft_style_scr);
  lv_scr_load(scr);
  lv_obj_clean(scr);

  lv_obj_t * title = lv_label_create(scr, NULL);
	lv_obj_set_style(title, &tft_style_lable_rel);
	lv_obj_set_pos(title,TITLE_XPOS,TITLE_YPOS);
	lv_label_set_text(title, creat_title_text());
  
  lv_refr_now(lv_refr_get_disp_refreshing());
	
	LV_IMG_DECLARE(bmp_pic);
	
    /*Create an Image button*/
       //buttonWifi = lv_imgbtn_create(scr, NULL);
	buttonHomeAll = lv_imgbtn_create(scr, NULL);
	buttonHomeX = lv_imgbtn_create(scr, NULL);
	//buttonContinue = lv_imgbtn_create(scr, NULL);
	buttonHomeY = lv_imgbtn_create(scr, NULL);
	buttonHomeZ = lv_imgbtn_create(scr, NULL);
	buttonBack = lv_imgbtn_create(scr, NULL);
	buttonOffAll = lv_imgbtn_create(scr, NULL);
	buttonOffXY = lv_imgbtn_create(scr, NULL);
	
	//lv_obj_set_event_cb_mks(buttonWifi, event_handler,ID_S_WIFI,"bmp_Wifi.bin",0);
	//lv_imgbtn_set_src(buttonWifi, LV_BTN_STATE_REL, &bmp_pic);
	//lv_imgbtn_set_src(buttonWifi, LV_BTN_STATE_PR, &bmp_pic);
	//lv_imgbtn_set_style(buttonWifi, LV_BTN_STATE_PR, &tft_style_lable_pre);
	//lv_imgbtn_set_style(buttonWifi, LV_BTN_STATE_REL, &tft_style_lable_rel);
	//lv_obj_clear_protect(buttonWifi, LV_PROTECT_FOLLOW);
	#if 1
	lv_obj_set_event_cb_mks(buttonHomeAll, event_handler,ID_H_ALL,"bmp_Zero.bin",0);
	lv_imgbtn_set_src(buttonHomeAll, LV_BTN_STATE_REL, &bmp_pic);
	lv_imgbtn_set_src(buttonHomeAll, LV_BTN_STATE_PR, &bmp_pic);
	lv_imgbtn_set_style(buttonHomeAll, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonHomeAll, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_event_cb_mks(buttonHomeX, event_handler,ID_H_X,"bmp_zeroX.bin",0);	
    lv_imgbtn_set_src(buttonHomeX, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonHomeX, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonHomeX, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonHomeX, LV_BTN_STATE_REL, &tft_style_lable_rel);

	//lv_obj_set_event_cb_mks(buttonContinue, event_handler,ID_S_CONTINUE,"bmp_Breakpoint.bin",0);	
    //lv_imgbtn_set_src(buttonContinue, LV_BTN_STATE_REL, &bmp_pic);
    //lv_imgbtn_set_src(buttonContinue, LV_BTN_STATE_PR, &bmp_pic);	
	//lv_imgbtn_set_style(buttonContinue, LV_BTN_STATE_PR, &tft_style_lable_pre);
	//lv_imgbtn_set_style(buttonContinue, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_event_cb_mks(buttonHomeY, event_handler,ID_H_Y,"bmp_zeroY.bin",0);	
    lv_imgbtn_set_src(buttonHomeY, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonHomeY, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonHomeY, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonHomeY, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_event_cb_mks(buttonHomeZ, event_handler,ID_H_Z,"bmp_zeroZ.bin",0);	
    lv_imgbtn_set_src(buttonHomeZ, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonHomeZ, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonHomeZ, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonHomeZ, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_event_cb_mks(buttonOffAll, event_handler,ID_H_OFF_ALL,"bmp_Motor_off.bin",0);	
    lv_imgbtn_set_src(buttonOffAll, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonOffAll, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonOffAll, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonOffAll, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_event_cb_mks(buttonOffXY, event_handler,ID_H_OFF_XY,"bmp_Motor_off.bin",0);	
    lv_imgbtn_set_src(buttonOffXY, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonOffXY, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonOffXY, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonOffXY, LV_BTN_STATE_REL, &tft_style_lable_rel);

	lv_obj_set_event_cb_mks(buttonBack, event_handler,ID_H_RETURN,"bmp_Return.bin",0);	
    lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_REL, &bmp_pic);
    lv_imgbtn_set_src(buttonBack, LV_BTN_STATE_PR, &bmp_pic);	
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_PR, &tft_style_lable_pre);
	lv_imgbtn_set_style(buttonBack, LV_BTN_STATE_REL, &tft_style_lable_rel);

	#endif
	/*lv_obj_set_pos(buttonWifi,INTERVAL_V,titleHeight);
	lv_obj_set_pos(buttonFan,BTN_X_PIXEL+INTERVAL_V*2,titleHeight);
	lv_obj_set_pos(buttonAbout,BTN_X_PIXEL*2+INTERVAL_V*3,titleHeight);
	lv_obj_set_pos(buttonContinue,BTN_X_PIXEL*3+INTERVAL_V*4,titleHeight);
	lv_obj_set_pos(buMotorOff,INTERVAL_V,  BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_obj_set_pos(buttonLanguage,BTN_X_PIXEL+INTERVAL_V*2,BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_obj_set_pos(buttonBack,BTN_X_PIXEL*3+INTERVAL_V*4,  BTN_Y_PIXEL+INTERVAL_H+titleHeight);*/

	//lv_obj_set_pos(buttonWifi,INTERVAL_V,titleHeight);
	lv_obj_set_pos(buttonHomeX,BTN_X_PIXEL+INTERVAL_V*2,titleHeight);
	lv_obj_set_pos(buttonHomeY,BTN_X_PIXEL*2+INTERVAL_V*3,titleHeight);
	//lv_obj_set_pos(buttonContinue,BTN_X_PIXEL*3+INTERVAL_V*4,titleHeight);
	lv_obj_set_pos(buttonHomeZ,BTN_X_PIXEL*3+INTERVAL_V*4,titleHeight);
	lv_obj_set_pos(buttonHomeAll,INTERVAL_V,titleHeight);
	lv_obj_set_pos(buttonOffAll,INTERVAL_V,  BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_obj_set_pos(buttonOffXY,BTN_X_PIXEL+INTERVAL_V*2,BTN_Y_PIXEL+INTERVAL_H+titleHeight);
	lv_obj_set_pos(buttonBack,BTN_X_PIXEL*3+INTERVAL_V*4,  BTN_Y_PIXEL+INTERVAL_H+titleHeight);

    /*Create a label on the Image button*/
	//lv_btn_set_layout(buttonWifi, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeAll, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeX, LV_LAYOUT_OFF);
	//lv_btn_set_layout(buttonContinue, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeY, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonHomeZ, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonOffAll, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonOffXY, LV_LAYOUT_OFF);
	lv_btn_set_layout(buttonBack, LV_LAYOUT_OFF);
	
    //lv_obj_t * labelWifi= lv_label_create(buttonWifi, NULL);
	lv_obj_t * labelHomeAll = lv_label_create(buttonHomeAll, NULL);
	lv_obj_t * labelHomeX= lv_label_create(buttonHomeX, NULL);
	//lv_obj_t * label_Continue = lv_label_create(buttonContinue, NULL);
	lv_obj_t * labelHomeY = lv_label_create(buttonHomeY, NULL);
	lv_obj_t * labelHomeZ = lv_label_create(buttonHomeZ, NULL);
	lv_obj_t * labelOffAll = lv_label_create(buttonOffAll, NULL);
	lv_obj_t * labelOffXY = lv_label_create(buttonOffXY, NULL);
	lv_obj_t * label_Back = lv_label_create(buttonBack, NULL);
	
	
	if(gCfgItems.multiple_language !=0)
	{
	       //lv_label_set_text(labelWifi, set_menu.wifi);
		//lv_obj_align(labelWifi, buttonWifi, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeAll, home_menu.home_all);
		lv_obj_align(labelHomeAll, buttonHomeAll, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeX,home_menu.home_x);
		lv_obj_align(labelHomeX, buttonHomeX, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

	       //lv_label_set_text(label_Continue, set_menu.breakpoint);
		//lv_obj_align(label_Continue, buttonContinue, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeY, home_menu.home_y);	
		lv_obj_align(labelHomeY, buttonHomeY, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelHomeZ, home_menu.home_z);	
		lv_obj_align(labelHomeZ, buttonHomeZ, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelOffAll, set_menu.motoroff);
		lv_obj_align(labelOffAll, buttonOffAll, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);

		lv_label_set_text(labelOffXY, set_menu.motoroffXY);
		lv_obj_align(labelOffXY, buttonOffXY, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);
		
		lv_label_set_text(label_Back, common_menu.text_back);
		lv_obj_align(label_Back, buttonBack, LV_ALIGN_IN_BOTTOM_MID,0, BUTTON_TEXT_Y_OFFSET);
	}
}

void lv_clear_home()
{
	lv_obj_del(scr);
}

#endif
