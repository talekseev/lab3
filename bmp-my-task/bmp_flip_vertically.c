/**
 * filter.c -- программа для отражения по вертикали 
 * изображение в формате BMP
 *
 * Copyright (c) 2018, Alekseev Trofim <talekseev@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 
#include "bmp.h"

/*
 * Вертикально отражает изображение
 * (Переворачивает его вверх ногами)
*/
void bmp_flip_vertically(bmp_image image)
{
    unsigned int i, j;
    
    /* Получаем линейные размеры изображения */
    unsigned int w = image.header.width;
    unsigned int h = image.header.height;
    
    /* Для всех строк пикселей */
    for (i = 0; i < (h/2); i++) {
        /* Для каждого пикселя */
        for(j = 0; j < w; j++) {
	    
	    /* Получаем компоненты цвета текущего пикселя*/
            double blue = image.pixel_array[0 * h * w + i * w + j];
            double green = image.pixel_array[1 * h * w + i * w + j];
            double red = image.pixel_array[2 * h * w + i * w + j];
	    
	    /* Преобразуем */
            image.pixel_array[0 * h * w + i * w + j] = image.pixel_array[0 * h * w + (h - i - 1) * w + j];
            image.pixel_array[1 * h * w + i * w + j] = image.pixel_array[1 * h * w + (h - i - 1) * w + j];
	    image.pixel_array[2 * h * w + i * w + j] = image.pixel_array[2 * h * w + (h - i - 1) * w + j];

	    image.pixel_array[0 * h * w + (h - i - 1) * w + j] = blue;
	    image.pixel_array[1 * h * w + (h - i - 1) * w + j] = green;
	    image.pixel_array[2 * h * w + (h - i - 1) * w + j] = red;
        }
    }
}
