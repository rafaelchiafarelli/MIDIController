#pragma once       
#include <assert.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>



struct  textCharSet {

   const char *cmd; 
   const char *first; 
   const char *second; 
   const char *third; 
   const char *fourth;
   };

#define TEXT_CHAR_SET {{NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {"tab",NULL, NULL, NULL, NULL },\
      {"enter", NULL, NULL, NULL, NULL },\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {"space", },\
      {"lShift",	"n_one",	NULL,NULL,NULL},\
      {"lAlt",		"n_three", "n_four",NULL,NULL},\
      {"lShift",	"n_three",NULL,NULL,NULL},\
      {"lShift",	"n_four",	NULL,NULL,NULL},\
      {"lShift", 	"n_five",	NULL,NULL,NULL},\
      {"lShift", 	"n_seven",	NULL,NULL,NULL},\
      {"singleCuotes",	NULL,NULL,NULL,NULL},\
      {"lShift", "n_nine",	NULL,NULL,NULL},\
      {"lShift", "n_zero",	NULL,NULL,NULL},\
      {"lShift", "n_eight",	NULL,NULL,NULL},\
      {"kPlus",	NULL,NULL,NULL,NULL},\
      {"comma",	NULL,NULL,NULL,NULL},\
      {"minus",	NULL,NULL,NULL,NULL},\
      {"dot",	NULL,NULL,NULL,NULL},\
      {"forwardSlash",	NULL,NULL,NULL,NULL},\
      {"n_zero",	NULL,NULL,NULL,NULL},\
      {"n_one",	NULL,NULL,NULL,NULL},\
      {"n_two",	NULL,NULL,NULL,NULL},\
      {"n_three",	NULL,NULL,NULL,NULL},\
      {"n_four",	NULL,NULL,NULL,NULL},\
      {"n_five",	NULL,NULL,NULL,NULL},\
      {"n_six",	NULL,NULL,NULL,NULL},\
      {"n_seven",	NULL,NULL,NULL,NULL},\
      {"n_eight",	NULL,NULL,NULL,NULL},\
      {"n_nine",	NULL,NULL,NULL,NULL},\
      {"twoDots",	NULL,NULL,NULL,NULL},\
      {"lShift", "twoDots",NULL,NULL,NULL},\
      {"lShift", "comma",NULL,NULL,NULL},\
      {"equal",	NULL,NULL,NULL,NULL},\
      {"lShift", "dot",NULL,NULL,NULL},\
      {"lShift", "forwardSlash",NULL,NULL,NULL},\
      {"lShift", "n_two",NULL,NULL,NULL},\
      {"lShift", "letter_a",	NULL,NULL,NULL},\
      {"lShift", "letter_b",	NULL,NULL,NULL},\
      {"lShift", "letter_c",	NULL,NULL,NULL},\
      {"lShift", "letter_d",	NULL,NULL,NULL},\
      {"lShift", "letter_e",	NULL,NULL,NULL},\
      {"lShift", "letter_f",	NULL,NULL,NULL},\
      {"lShift", "letter_g",	NULL,NULL,NULL},\
      {"lShift", "letter_h",	NULL,NULL,NULL},\
      {"lShift", "letter_i",	NULL,NULL,NULL},\
      {"lShift", "letter_j",	NULL,NULL,NULL},\
      {"lShift", "letter_k",	NULL,NULL,NULL},\
      {"lShift", "letter_l",	NULL,NULL,NULL},\
      {"lShift", "letter_m",	NULL,NULL,NULL},\
      {"lShift", "letter_n",	NULL,NULL,NULL},\
      {"lShift", "letter_o",	NULL,NULL,NULL},\
      {"lShift", "letter_p",	NULL,NULL,NULL},\
      {"lShift", "letter_q",	NULL,NULL,NULL},\
      {"lShift", "letter_r",	NULL,NULL,NULL},\
      {"lShift", "letter_s",	NULL,NULL,NULL},\
      {"lShift", "letter_t",	NULL,NULL,NULL},\
      {"lShift", "letter_u",	NULL,NULL,NULL},\
      {"lShift", "letter_v",	NULL,NULL,NULL},\
      {"lShift", "letter_w",	NULL,NULL,NULL},\
      {"lShift", "letter_x",	NULL,NULL,NULL},\
      {"lShift", "letter_y",	NULL,NULL,NULL},\
      {"lShift", "letter_z",	NULL,NULL,NULL},\
      {"oBracket",	NULL,NULL,NULL,NULL},\
      {"backSlash",NULL,NULL,NULL,NULL},\
      {"cBracket",	NULL,NULL,NULL,NULL},\
      {"lShift", "Tilde",NULL,NULL,NULL},\
      {"lShift", "minus",NULL,NULL,NULL},\
      {"lShift", "acuteAcent",NULL,NULL,NULL},\
      {"letter_a",	NULL,NULL,NULL,NULL},\
      {"letter_b",	NULL,NULL,NULL,NULL},\
      {"letter_c",	NULL,NULL,NULL,NULL},\
      {"letter_d",	NULL,NULL,NULL,NULL},\
      {"letter_e",	NULL,NULL,NULL,NULL},\
      {"letter_f",	NULL,NULL,NULL,NULL},\
      {"letter_g",	NULL,NULL,NULL,NULL},\
      {"letter_h",	NULL,NULL,NULL,NULL},\
      {"letter_i",	NULL,NULL,NULL,NULL},\
      {"letter_j",	NULL,NULL,NULL,NULL},\
      {"letter_k",	NULL,NULL,NULL,NULL},\
      {"letter_l",	NULL,NULL,NULL,NULL},\
      {"letter_m",	NULL,NULL,NULL,NULL},\
      {"letter_n",	NULL,NULL,NULL,NULL},\
      {"letter_o",	NULL,NULL,NULL,NULL},\
      {"letter_p",	NULL,NULL,NULL,NULL},\
      {"letter_q",	NULL,NULL,NULL,NULL},\
      {"letter_r",	NULL,NULL,NULL,NULL},\
      {"letter_s",	NULL,NULL,NULL,NULL},\
      {"letter_t",	NULL,NULL,NULL,NULL},\
      {"letter_u",	NULL,NULL,NULL,NULL},\
      {"letter_v",	NULL,NULL,NULL,NULL},\
      {"letter_w",	NULL,NULL,NULL,NULL},\
      {"letter_x",	NULL,NULL,NULL,NULL},\
      {"letter_y",	NULL,NULL,NULL,NULL},\
      {"letter_z",	NULL,NULL,NULL,NULL},\
      {"lShift", "oBracket",NULL,NULL,NULL},\
      {"lShift", "backSlash",NULL,NULL,NULL},\
      {"lShift", "cBracket",NULL,NULL,NULL},\
      {"Tilde",NULL,NULL,NULL,NULL},\
      {NULL,NULL,NULL,NULL,NULL},\
      {"lAlt", "n_one","n_two", "n_eight",NULL},\
      {"lAlt", "n_one", "n_two", "n_nine",NULL},\
      {"lAlt", "n_one", "n_three", "n_zero",NULL},\
      {"lAlt", "n_one", "n_three", "n_one",NULL},\
      {"lAlt", "n_one", "n_three", "n_two",NULL},\
      {"lAlt", "n_one", "n_three", "n_three",NULL},\
      {"lAlt", "n_one", "n_three", "n_four",NULL},\
      {"lAlt", "n_one", "n_three", "n_five",NULL},\
      {"lAlt", "n_one", "n_three", "n_six",NULL},\
      {"lAlt", "n_one", "n_three", "n_seven",NULL},\
      {"lAlt", "n_one", "n_three", "n_eight",NULL},\
      {"lAlt", "n_one", "n_three", "n_nine",NULL},\
      {"lAlt", "n_one", "n_four", "n_zero",NULL},\
      {"lAlt", "n_one", "n_four", "n_one",NULL},\
      {"lAlt", "n_one", "n_four", "n_five",NULL},\
      {"lAlt", "n_one", "n_four", "n_six",NULL},\
      {"lAlt", "n_one", "n_four", "n_seven",NULL},\
      {"lAlt", "n_one", "n_four", "n_eight",NULL},\
      {"lAlt", "n_one", "n_four", "n_nine",NULL},\
      {"lAlt", "n_one", "n_five", "n_zero",NULL},\
      {"lAlt", "n_one", "n_five", "n_one",NULL},\
      {"lAlt", "n_one", "n_five", "n_two",NULL},\
      {"lAlt", "n_one", "n_five", "n_five",NULL},\
      {"lAlt", "n_one", "n_five", "n_six",NULL},\
      {"lAlt", "n_one", "n_five", "n_seven",NULL},\
      {"lAlt", "n_one", "n_five", "n_eight",NULL},\
      {"lAlt", "n_one", "n_five", "n_nine",NULL},\
      {"lAlt", "n_one", "n_six", "n_zero",NULL},\
      {"lAlt", "n_one", "n_six", "n_one",NULL},\
      {"lAlt", "n_one", "n_six", "n_two",NULL},\
      {"lAlt", "n_one", "n_six", "n_three",NULL},\
      {"lAlt", "n_one", "n_six", "n_four",NULL},\
      {"lAlt", "n_one", "n_six", "n_five",NULL},\
      {"lAlt", "n_one", "n_six", "n_six",NULL},\
      {"lAlt", "n_one", "n_six", "n_seven",NULL},\
      {"lAlt", "n_one", "n_six", "n_eight",NULL},\
      {"lAlt", "n_one", "n_seven", "n_zero",NULL},\
      {"lAlt", "n_one", "n_seven", "n_one",NULL},\
      {"lAlt", "n_one", "n_seven", "n_two",NULL},\
      {"lAlt", "n_one", "n_seven", "n_three",NULL},\
      {"lAlt", "n_one", "n_seven", "n_four",NULL},\
      {"lAlt", "n_one", "n_seven", "n_five",NULL},\
      {"lAlt", "n_one", "n_seven", "n_nine",NULL},\
      {"lAlt", "n_two", "n_two", "n_five",NULL},\
      {"lAlt", "n_two", "n_three", "n_zero",NULL},\
      {"lAlt", "n_two", "n_four", "n_one",NULL},\
      {"lAlt", "n_two", "n_four", "n_eight",NULL},\
      {"lAlt", "n_two", "n_four", "n_nine",NULL},\
      {"lAlt", "n_two", "n_five", "n_zero",NULL},\
      {"lAlt", "n_two", "n_five", "n_three",NULL},\
      {"lAlt", "n_zero","n_one", "n_two",  "n_eight"},\
      {"lAlt", "n_zero","n_one", "n_three","n_two"},\
      {"lAlt", "n_zero","n_one", "n_three","n_three"},\
      {"lAlt", "n_zero","n_one", "n_three","n_four"},\
      {"lAlt", "n_zero","n_one", "n_three","n_five"},\
      {"lAlt", "n_zero","n_one", "n_three","n_six"},\
      {"lAlt", "n_zero","n_one", "n_three","n_seven"},\
      {"lAlt", "n_zero","n_one", "n_three","n_eight"},\
      {"lAlt", "n_zero","n_one", "n_three","n_nine"},\
      {"lAlt", "n_zero","n_one", "n_four", "n_zero"},\
      {"lAlt", "n_zero","n_one", "n_four", "n_five"},\
      {"lAlt", "n_zero","n_one", "n_four", "n_six"},\
      {"lAlt", "n_zero","n_one", "n_four", "n_seven"},\
      {"lAlt", "n_zero","n_one", "n_four", "n_eight"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_zero"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_one"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_two"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_three"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_four"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_five"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_six"},\
      {"lAlt", "n_zero","n_one", "n_five", "n_nine"},\
      {"lAlt", "n_zero","n_one", "n_six",  "n_eight"},\
      {"lAlt", "n_zero","n_one", "n_six",  "n_nine"},\
      {"lAlt", "n_zero","n_one", "n_seven","n_four"},\
      {"lAlt", "n_zero","n_one", "n_seven","n_five"},\
      {"lAlt", "n_zero","n_one", "n_seven","n_nine"},\
      {"lAlt", "n_zero","n_one", "n_eight","n_zero"},\
      {"lAlt", "n_zero","n_one", "n_eight","n_four"},\
      {"lAlt", "n_zero","n_one", "n_eight","n_five"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_zero"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_two"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_three"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_four"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_five"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_six"},\
      {"lAlt", "n_zero","n_one", "n_nine", "n_seven"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_zero"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_one"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_two"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_three"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_four"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_five"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_six"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_seven"},\
      {"lAlt", "n_zero","n_two", "n_zero", "n_eight"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_zero"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_one"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_two"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_three"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_four"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_five"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_six"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_seven"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_eight"},\
      {"lAlt", "n_zero","n_two", "n_one",  "n_nine"},\
      {"lAlt", "n_zero","n_two", "n_two",  "n_zero"},\
      {"lAlt", "n_zero","n_two", "n_two",  "n_one"},\
      {"lAlt", "n_zero","n_two", "n_two",  "n_two"},\
      {"lAlt", "n_zero","n_two", "n_two",  "n_seven"},\
      {"lAlt", "n_zero","n_two", "n_four", "n_zero"},\
      {"lAlt", "n_zero","n_two", "n_four", "n_five"},\
      {"lAlt", "n_zero","n_two", "n_four", "n_seven"},\
      {"lAlt", "n_zero","n_two", "n_four", "n_eight"},\
      {"lAlt", "n_zero","n_two", "n_five", "n_two"},\
      {"lAlt", "n_zero","n_two", "n_five", "n_three"},\
      {"lAlt", "n_zero", "n_two", "n_five", "n_four"}};