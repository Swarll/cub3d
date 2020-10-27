/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:50:27 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/27 15:58:51 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned char* createBitmapFileHeader (t_gameinf *game, int stride)
{
	int fileSize = game->bmp.file_h_s + game->bmp.inf_h_s + (stride * game->res_y);

	static unsigned char fileHeader[] = {
		0,0,     /// signature
		0,0,0,0, /// image file size in bytes
		0,0,0,0, /// reserved
		0,0,0,0, /// start of pixel array
	};

	fileHeader[ 0] = (unsigned char)('B');
	fileHeader[ 1] = (unsigned char)('M');
	fileHeader[ 2] = (unsigned char)(fileSize      );
	fileHeader[ 3] = (unsigned char)(fileSize >>  8);
	fileHeader[ 4] = (unsigned char)(fileSize >> 16);
	fileHeader[ 5] = (unsigned char)(fileSize >> 24);
	fileHeader[10] = (unsigned char)(game->bmp.file_h_s + game->bmp.inf_h_s);

	return fileHeader;
}

unsigned char* createBitmapInfoHeader (t_gameinf *game)
{
	static unsigned char infoHeader[] = {
		0,0,0,0, /// header size
		0,0,0,0, /// image width
		0,0,0,0, /// image height
		0,0,     /// number of color planes
		0,0,     /// bits per pixel
		0,0,0,0, /// compression
		0,0,0,0, /// image size
		0,0,0,0, /// horizontal resolution
		0,0,0,0, /// vertical resolution
		0,0,0,0, /// colors in color table
		0,0,0,0, /// important color count
	};

	infoHeader[ 0] = (unsigned char)(game->bmp.inf_h_s);
	infoHeader[ 4] = (unsigned char)(game->res_x);
	infoHeader[ 5] = (unsigned char)(game->res_x >>  8);
	infoHeader[ 6] = (unsigned char)(game->res_x >> 16);
	infoHeader[ 7] = (unsigned char)(game->res_x >> 24);
	infoHeader[ 8] = (unsigned char)(game->res_y);
	infoHeader[ 9] = (unsigned char)(game->res_y >>  8);
	infoHeader[10] = (unsigned char)(game->res_y >> 16);
	infoHeader[11] = (unsigned char)(game->res_y >> 24);
	infoHeader[12] = (unsigned char)(1);
	infoHeader[14] = (unsigned char)(game->bmp.bpp * 8);

	return infoHeader;
}

void gen_bpp (unsigned char* image, t_gameinf *game, char* imageFileName)
{
	int widthInBytes = game->res_x * game->bmp.bpp ;

	unsigned char padding[3] = {0, 0, 0};
	int paddingSize = (4 - (widthInBytes) % 4) % 4;

	int stride = (widthInBytes) + paddingSize;

	FILE* imageFile = fopen(imageFileName, "wb");

	unsigned char* fileHeader = createBitmapFileHeader(game, stride);
	fwrite(fileHeader, 1, game->bmp.file_h_s, imageFile);

	unsigned char* infoHeader = createBitmapInfoHeader(game);
	fwrite(infoHeader, 1, game->bmp.inf_h_s, imageFile);

	int i;
	for (i = 0; i < game->res_y; i++) {
		fwrite(image + (i*widthInBytes), game->bmp.bpp , game->res_x, imageFile);
		fwrite(padding, 1, paddingSize, imageFile);
	}

	fclose(imageFile);
}

void    start_bmp(t_gameinf *game)
{
	unsigned image[game->res_y][game->res_x];
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < game->res_x)
	{
		i = 0;
		while (j < game->res_y)
		{
			image[i][j] = (char)game->img[i + j * game->res_x];
			j++;
		}
		i++;
	}
	gen_bpp((unsigned char*) image, game, "screenshot");
	printf("Image generated!!");
}