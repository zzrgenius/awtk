﻿/**
 * File:   lcd.h
 * Author: Li XianJing <xianjimli@hotmail.com>
 * Brief:  lcd interface
 *
 * Copyright (c) 2018 - 2018  Li XianJing <xianjimli@hotmail.com>
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-01-13 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef LFTK_LCD_H
#define LFTK_LCD_H

#include "base/rect.h"
#include "base/font.h"
#include "base/bitmap.h"
#include "base/vgcanvas.h"

BEGIN_C_DECLS

struct _lcd_t;
typedef struct _lcd_t lcd_t;

typedef ret_t (*lcd_begin_frame_t)(lcd_t* lcd, rect_t* dirty_rect);

typedef ret_t (*lcd_set_global_alpha_t)(lcd_t* lcd, uint8_t alpha);
typedef ret_t (*lcd_set_text_color_t)(lcd_t* lcd, color_t color);
typedef ret_t (*lcd_set_stroke_color_t)(lcd_t* lcd, color_t color);
typedef ret_t (*lcd_set_fill_color_t)(lcd_t* lcd, color_t color);

typedef ret_t (*lcd_draw_vline_t)(lcd_t* lcd, xy_t x, xy_t y, wh_t h);
typedef ret_t (*lcd_draw_hline_t)(lcd_t* lcd, xy_t x, xy_t y, wh_t w);
typedef ret_t (*lcd_draw_points_t)(lcd_t* lcd, point_t* points, uint32_t nr);
typedef ret_t (*lcd_fill_rect_t)(lcd_t* lcd, xy_t x, xy_t y, wh_t w, wh_t h);
typedef ret_t (*lcd_draw_glyph_t)(lcd_t* lcd, glyph_t* glyph, rect_t* src, xy_t x, xy_t y);
typedef ret_t (*lcd_draw_image_t)(lcd_t* lcd, bitmap_t* img, rect_t* src, rect_t* dst);
typedef vgcanvas_t* (*lcd_get_vgcanvas_t)(lcd_t* lcd);

typedef ret_t (*lcd_end_frame_t)(lcd_t* lcd);
typedef ret_t (*lcd_destroy_t)(lcd_t* lcd);

/**
 * @class lcd_t 
 * 显示设备抽象基类。
 */
struct _lcd_t {
  lcd_begin_frame_t begin_frame;
  lcd_set_global_alpha_t set_global_alpha;
  lcd_set_text_color_t set_text_color;
  lcd_set_stroke_color_t set_stroke_color;
  lcd_set_fill_color_t set_fill_color;
  lcd_draw_vline_t draw_vline;
  lcd_draw_hline_t draw_hline;
  lcd_fill_rect_t fill_rect;
  lcd_draw_image_t draw_image;
  lcd_draw_glyph_t draw_glyph;
  lcd_draw_points_t draw_points;
  lcd_end_frame_t end_frame;
  lcd_get_vgcanvas_t get_vgcanvas;

  lcd_destroy_t destroy;

  /**
   * @property {wh_t} w
   * @readonly
   * 屏幕的宽度
   */
  wh_t w; 
  /**
   * @property {wh_t} height
   * @readonly
   * 屏幕的高度
   */
  wh_t h; 
  /**
   * @property {uint8_t} global_alpha
   * @readonly
   * 全局alpha
   */
  uint8_t global_alpha;
  /**
   * @property {color_t} text_color
   * @readonly
   * 文本颜色
   */
  color_t text_color;
  /**
   * @property {color_t} fill_color
   * @readonly
   * 填充颜色
   */
  color_t fill_color;
  /**
   * @property {color_t} stroke_color
   * @readonly
   * 线条颜色
   */
  color_t stroke_color;
  rect_t* dirty_rect;
};

/**
 * @method lcd_begin_frame
 * 准备绘制。
 * @param {lcd_t*} lcd lcd对象。
 * @param {rect_t*} dirty_rect 需要绘制的区域。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_begin_frame(lcd_t* lcd, rect_t* dirty_rect);

/**
 * @method lcd_set_global_alpha
 * 设置全局alpha。
 * @param {lcd_t*} lcd lcd对象。
 * @param {uint8_t} alpha 全局alpha。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_set_global_alpha(lcd_t* lcd, uint8_t alpha);

/**
 * @method lcd_set_text_color
 * 设置文本颜色。
 * @param {lcd_t*} lcd lcd对象。
 * @param {color_t} color 颜色。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_set_text_color(lcd_t* lcd, color_t color);

/**
 * @method lcd_set_stroke_color
 * 设置线条颜色。
 * @param {lcd_t*} lcd lcd对象。
 * @param {color_t} color 颜色。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_set_stroke_color(lcd_t* lcd, color_t color);

/**
 * @method lcd_set_fill_color
 * 设置填充颜色。
 * @param {lcd_t*} lcd lcd对象。
 * @param {color_t} color 颜色。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_set_fill_color(lcd_t* lcd, color_t color);

/**
 * @method lcd_draw_vline
 * 绘制一条垂直线。
 * @param {lcd_t*} lcd lcd对象。
 * @param {xy_t*} x x坐标。
 * @param {xy_t*} y y坐标。
 * @param {xy_t*} h 直线高度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_draw_vline(lcd_t* lcd, xy_t x, xy_t y, wh_t h);

/**
 * @method lcd_draw_hline
 * 绘制一条水平线。
 * @param {lcd_t*} lcd lcd对象。
 * @param {xy_t*} x x坐标。
 * @param {xy_t*} y y坐标。
 * @param {xy_t*} w 直线宽度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_draw_hline(lcd_t* lcd, xy_t x, xy_t y, wh_t w);

/**
 * @method lcd_draw_points
 * 绘制一组点。
 * @param {lcd_t*} lcd lcd对象。
 * @param {point_t*} points 要绘制的点集合。
 * @param {uint32_t} nr 点的个数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_draw_points(lcd_t* lcd, point_t* points, uint32_t nr);

/**
 * @method lcd_fill_rect
 * 绘制实心矩形。
 * @param {lcd_t*} lcd lcd对象。
 * @param {xy_t} x x坐标。
 * @param {xy_t} y y坐标。
 * @param {wh_t} w 宽度。
 * @param {wh_t} h 高度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_fill_rect(lcd_t* lcd, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method lcd_draw_glyph
 * 绘制字符。
 * @param {lcd_t*} lcd lcd对象。
 * @param {glyph_t*} glyph 字模
 * @param {rect_t*} src 只绘制指定区域的部分。
 * @param {xy_t} x x坐标。
 * @param {xy_t} y y坐标。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_draw_glyph(lcd_t* lcd, glyph_t* glyph, rect_t* src, xy_t x, xy_t y);

/**
 * @method lcd_draw_image
 * 绘制图片。
 * @param {lcd_t*} lcd lcd对象。
 * @param {bitmap_t*} img 图片。 
 * @param {rect_t*} src 只绘制指定区域的部分。
 * @param {rect_t*} dst 绘制到目标区域。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_draw_image(lcd_t* lcd, bitmap_t* img, rect_t* src, rect_t* dst);

/**
 * @method lcd_get_vgcanvas
 * 获取矢量图canvas。
 * @param {lcd_t*} lcd lcd对象。
 *
 * @return {vgcanvas_t*} 返回矢量图canvas。
 */
vgcanvas_t* lcd_get_vgcanvas(lcd_t* lcd);

/**
 * @method lcd_end_frame
 * 完成绘制，同步到显示设备。
 * @param {lcd_t*} lcd lcd对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t lcd_end_frame(lcd_t* lcd);

ret_t lcd_destroy(lcd_t* lcd);

END_C_DECLS

#endif /*LFTK_LCD_H*/
