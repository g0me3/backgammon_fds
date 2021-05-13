
		INCLUDE		"..\macroses.inc"

;--------------------R-A-M----------------------

		ORG $0000

word_0:
		.BYTE 0,0
byte_2:
		.BYTE 0
byte_3:
		.BYTE 0
byte_4:
		.BYTE 0
byte_5:
		.BYTE 0
byte_6:
		.BYTE 0
byte_7:
		.BYTE 0
byte_8:
		.BYTE 0
byte_9:
		.BYTE 0
byte_A:
		.BYTE 0
byte_B:
		.BYTE 0
byte_C:
		.BYTE 0
byte_D:
		.BYTE 0
byte_E:
		.BYTE 0
byte_F:
		.BYTE 0
word_10:
		.BYTE 0,0
byte_12:
		.BYTE 0
byte_13:
		.BYTE 0
byte_14:
		.BYTE 0
byte_15:
		.BYTE 0
;		.BYTE 0
;		.BYTE 0
;		.BYTE 0
;		.BYTE 0
byte_1A:
		.BYTE 0
byte_1B:
		.BYTE 0
_tmp1Cw:
		.BYTE 0,0
byte_1E:
		.BYTE 0
byte_1F:
		.BYTE 0
_tmp20w:
		.BYTE 0,0
byte_22:
		.BYTE 0
byte_23:
		.BYTE 0
_pads_held:
		.BYTE 0,0
_pads_press:
		.BYTE 0,0
_pad_tmp2:
		.BYTE 0,0
_pad_tmp3:
		.BYTE 0,0
_pad_tmp0:
		.BYTE 0,0
_pad_tmp1:
		.BYTE 0,0
_pads_tmp4:
		.BYTE 0,0
byte_32:
		.BYTE 0
_frames_counter:
		.BYTE 0
_nmi_disable_flush:
		.BYTE 0
_nmi_flag:
		.BYTE 0
_nmi_counter:
		.BYTE 0
_ppu_dequeue_req:
		.BYTE 0
;		.BYTE 0
_nmi_tlm_lib_idx:
		.BYTE 0
;		.BYTE 0
_main02_sub_idx:
		.BYTE 0
byte_3C:
		.BYTE 0
byte_3D:
		.BYTE 0
byte_3E:
		.BYTE 0
byte_3F:
		.BYTE 0
_1p_cpu_ctrl_flag:
		.BYTE 0
_2p_cpu_ctrl_flag:
		.BYTE 0
_cur_player_idx:
		.BYTE 0
byte_43:
		.BYTE 0
_ingame_sub_idx:
		.BYTE 0
byte_45:
		.BYTE 0
byte_46:
		.BYTE 0
byte_47:
		.BYTE 0
byte_48:
		.BYTE 0
byte_49:
		.BYTE 0
byte_4A:
		.BYTE 0
_tmp4Bb:
		.BYTE 0
_timer_minutes:
		.BYTE 0
byte_4D:
		.BYTE 0
_tmp_idx:
		.BYTE 0
byte_4F:
		.BYTE 0
byte_50:
		.BYTE 0
_tmp51w:
		.BYTE 0,0
_tmp53w:
		.BYTE 0,0
byte_55:
		.BYTE 0
_main00_sub_idx:
		.BYTE 0
byte_57:
		.BYTE 0
byte_58:
		.BYTE 0
byte_59:
		.BYTE 0
byte_5A:
		.BYTE 0
byte_5B:
		.BYTE 0
byte_5C:
		.BYTE 0
byte_5D:
		.BYTE 0
byte_5E:
		.BYTE 0
byte_5F:
		.BYTE 0
byte_60:
		.BYTE 0
byte_61:
		.BYTE 0
byte_62:
		.BYTE 0
_spr_buf_pos:
		.BYTE 0
byte_64:
		.BYTE 0
byte_65:
		.BYTE 0
byte_66:
		.BYTE 0
byte_67:
		.BYTE 0
byte_68:
		.BYTE 0
byte_69:
		.BYTE 0
_spr_lib_idx:
		.BYTE 0
byte_6B:
		.BYTE 0
byte_6C:
		.BYTE 0
byte_6D:
		.BYTE 0
byte_6E:
		.BYTE 0
byte_6F:
		.BYTE 0
byte_70:
		.BYTE 0
byte_71:
		.BYTE 0
byte_72:
		.BYTE 0
byte_73:
		.BYTE 0
byte_74:
		.BYTE 0
byte_75:
		.BYTE 0
byte_76:
		.BYTE 0
byte_77:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_7A:
		.BYTE 0
		.BYTE 0
byte_7C:
		.BYTE 0
byte_7D:
		.BYTE 0
byte_7E:
		.BYTE 0
		.BYTE 0
byte_80:
		.BYTE 0
byte_81:
		.BYTE 0
byte_82:
		.BYTE 0
byte_83:
		.BYTE 0
byte_84:
		.BYTE 0
byte_85:
		.BYTE 0
byte_86:
		.BYTE 0
byte_87:
		.BYTE 0
byte_88:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_8B:
		.BYTE 0
		.BYTE 0
byte_8D:
		.BYTE 0
		.BYTE 0
byte_8F:
		.BYTE 0
byte_90:
		.BYTE 0
byte_91:
		.BYTE 0
byte_92:
		.BYTE 0
byte_93:
		.BYTE 0
byte_94:
		.BYTE 0
byte_95:
		.BYTE 0
byte_96:
		.BYTE 0
byte_97:
		.BYTE 0
byte_98:
		.BYTE 0
byte_99:
		.BYTE 0
byte_9A:
		.BYTE 0
byte_9B:
		.BYTE 0
byte_9C:
		.BYTE 0
byte_9D:
		.BYTE 0
byte_9E:
		.BYTE 0
byte_9F:
		.BYTE 0
byte_A0:
		.BYTE 0
byte_A1:
		.BYTE 0
byte_A2:
		.BYTE 0
byte_A3:
		.BYTE 0
byte_A4:
		.BYTE 0
byte_A5:
		.BYTE 0
byte_A6:
		.BYTE 0
byte_A7:
		.BYTE 0
byte_A8:
		.BYTE 0
byte_A9:
		.BYTE 0
byte_AA:
		.BYTE 0
byte_AB:
		.BYTE 0
byte_AC:
		.BYTE 0
byte_AD:
		.BYTE 0
byte_AE:
		.BYTE 0
byte_AF:
		.BYTE 0
byte_B0:
		.BYTE 0
byte_B1:
		.BYTE 0
byte_B2:
		.BYTE 0
byte_B3:
		.BYTE 0
byte_B4:
		.BYTE 0
byte_B5:
		.BYTE 0
byte_B6:
		.BYTE 0
byte_B7:
		.BYTE 0
byte_B8:
		.BYTE 0
byte_B9:
		.BYTE 0
byte_BA:
		.BYTE 0
byte_BB:
		.BYTE 0
byte_BC:
		.BYTE 0
byte_BD:
		.BYTE 0
byte_BE:
		.BYTE 0
byte_BF:
		.BYTE 0
byte_C0:
		.BYTE 0
byte_C1:
		.BYTE 0
byte_C2:
		.BYTE 0
byte_C3:
		.BYTE 0
byte_C4:
		.BYTE 0
byte_C5:
		.BYTE 0
byte_C6:
		.BYTE 0
byte_C7:
		.BYTE 0
byte_C8:
		.BYTE 0
byte_C9:
		.BYTE 0
byte_CA:
		.BYTE 0
byte_CB:
		.BYTE 0
byte_CC:
		.BYTE 0
byte_CD:
		.BYTE 0
byte_CE:
		.BYTE 0
byte_CF:
		.BYTE 0
byte_D0:
		.BYTE 0
byte_D1:
		.BYTE 0
byte_D2:
		.BYTE 0
byte_D3:
		.BYTE 0
byte_D4:
		.BYTE 0
byte_D5:
		.BYTE 0
		.BYTE 0
byte_D7:
		.BYTE 0
byte_D8:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_DE:
		.BYTE 0
byte_DF:
		.BYTE 0
word_E0:
		.BYTE 0,0
word_E2:
		.BYTE 0,0
word_E4:
		.BYTE 0,0
byte_E6:
		.BYTE 0
byte_E7:
		.BYTE 0
byte_E8:
		.BYTE 0
byte_E9:
		.BYTE 0
byte_EA:
		.BYTE 0
byte_EB:
		.BYTE 0
byte_EC:
		.BYTE 0
byte_ED:
		.BYTE 0
byte_EE:
		.BYTE 0
byte_EF:
		.BYTE 0
		.BYTE 0
byte_F1:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_F5:
		.BYTE 0
byte_F6:
		.BYTE 0
byte_F7:
		.BYTE 0
byte_F8:
		.BYTE 0
byte_F9:
		.BYTE 0
byte_FA:
		.BYTE 0
byte_FB:
		.BYTE 0
byte_FC:
		.BYTE 0
byte_FD:
		.BYTE 0
_ppu_mask_shadow:
		.BYTE 0
_ppu_ctrl_shadow:
		.BYTE 0

		ECHO "-------------"
		ECHO "zero ram free:",[$100-.]
		ECHO "-------------"

		ORG $0100

byte_100:
		.BYTE 0
byte_101:
		.BYTE 0
byte_102:
		.BYTE 0
byte_103:
		.BYTE 0
byte_104:
		.BYTE 0
byte_105:
		.BYTE 0
byte_106:
		.BYTE 0
byte_107:
		.BYTE 0
byte_108:
		.BYTE 0
byte_109:
		.BYTE 0
byte_10A:
		.BYTE 0
_nmi_tlmB2_ram:
		.BYTE 0
byte_10C:
		.BYTE 0
byte_10D:
		.BYTE 0
byte_10E:
		.BYTE 0
byte_10F:
		.BYTE 0
byte_110:
		.BYTE 0
byte_111:
		.BYTE 0
byte_112:
		.BYTE 0
byte_113:
		.BYTE 0
byte_114:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_117:
		.BYTE 0
byte_118:
		.BYTE 0
byte_119:
		.BYTE 0
byte_11A:
		.BYTE 0
byte_11B:
		.BYTE 0
byte_11C:
		.BYTE 0
byte_11D:
		.BYTE 0,0,0,0,0,0,0,0
byte_125:
		.BYTE 0
byte_126:
		.BYTE 0
byte_127:
		.BYTE 0
byte_128:
		.BYTE 0
byte_129:
		.BYTE 0,0
byte_12B:
		.BYTE 0
byte_12C:
		.BYTE 0,0,0,0,0,0
byte_132:
		.BYTE 0,0,0,0,0,0
byte_138:
		.BYTE 0,0,0
byte_13B:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0
byte_148:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0
byte_154:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
byte_184:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0
_pal_buf1:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0
_pal_buf2:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_pal_buf3:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_stack;
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0

		ORG $0200

_spr_buf:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

		ORG $0300

byte_300:
		.BYTE 0
byte_301:
		.BYTE 0
byte_302:
		.BYTE 0
byte_303:
		.BYTE 0
byte_304:
		.BYTE 0
byte_305:
		.BYTE 0
byte_306:
		.BYTE 0
byte_307:
		.BYTE 0
byte_308:
		.BYTE 0
byte_309:
		.BYTE 0
byte_30A:
		.BYTE 0
byte_30B:
		.BYTE 0
byte_30C:
		.BYTE 0
byte_30D:
		.BYTE 0
		.BYTE 0
byte_30F:
		.BYTE 0
byte_310:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_314:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_319:
		.BYTE 0
byte_31A:
		.BYTE 0
byte_31B:
		.BYTE 0
byte_31C:
		.BYTE 0
byte_31D:
		.BYTE 0
byte_31E:
		.BYTE 0
byte_31F:
		.BYTE 0
byte_320:
		.BYTE 0
byte_321:
		.BYTE 0
byte_322:
		.BYTE 0
byte_323:
		.BYTE 0
byte_324:
		.BYTE 0
byte_325:
		.BYTE 0
byte_326:
		.BYTE 0
byte_327:
		.BYTE 0
byte_328:
		.BYTE 0
byte_329:
		.BYTE 0
byte_32A:
		.BYTE 0
byte_32B:
		.BYTE 0
byte_32C:
		.BYTE 0
byte_32D:
		.BYTE 0
byte_32E:
		.BYTE 0
byte_32F:
		.BYTE 0
byte_330:
		.BYTE 0
byte_331:
		.BYTE 0
byte_332:
		.BYTE 0
byte_333:
		.BYTE 0
byte_334:
		.BYTE 0
byte_335:
		.BYTE 0
byte_336:
		.BYTE 0
byte_337:
		.BYTE 0
byte_338:
		.BYTE 0
byte_339:
		.BYTE 0
byte_33A:
		.BYTE 0
byte_33B:
		.BYTE 0
byte_33C:
		.BYTE 0
byte_33D:
		.BYTE 0
byte_33E:
		.BYTE 0
byte_33F:
		.BYTE 0
byte_340:
		.BYTE 0
byte_341:
		.BYTE 0
byte_342:
		.BYTE 0
byte_343:
		.BYTE 0
byte_344:
		.BYTE 0
byte_345:
		.BYTE 0
byte_346:
		.BYTE 0
byte_347:
		.BYTE 0
byte_348:
		.BYTE 0
byte_349:
		.BYTE 0
byte_34A:
		.BYTE 0
byte_34B:
		.BYTE 0
byte_34C:
		.BYTE 0
byte_34D:
		.BYTE 0
byte_34E:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_3C0:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_3E0:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_3FF:
		.BYTE 0
byte_400:
		.BYTE 0
byte_401:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_413:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_419:
		.BYTE 0
byte_41A:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_420:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_433:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_439:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_43F:
		.BYTE 0
byte_440:
		.BYTE 0
byte_441:
		.BYTE 0
byte_442:
		.BYTE 0
byte_443:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_446:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_453:
		.BYTE 0
byte_454:
		.BYTE 0
byte_455:
		.BYTE 0
byte_456:
		.BYTE 0
byte_457:
		.BYTE 0
byte_458:
		.BYTE 0
byte_459:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_460:
		.BYTE 0
byte_461:
		.BYTE 0
byte_462:
		.BYTE 0
byte_463:
		.BYTE 0
byte_464:
		.BYTE 0
byte_465:
		.BYTE 0
byte_466:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_472:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_476:
		.BYTE 0
byte_477:
		.BYTE 0
byte_478:
		.BYTE 0
byte_479:
		.BYTE 0
byte_47A:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_47F:
		.BYTE 0
byte_480:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_493:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_499:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_49F:
		.BYTE 0
byte_4A0:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_4B9:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
_rand_seed:
		.BYTE 0
byte_501:
		.BYTE 0
byte_502:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_50B:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_510:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
_pads_raw:
		.BYTE 0,0
_pause_mode_flag:
		.BYTE 0
byte_533:
		.BYTE 0
byte_534:
		.BYTE 0
byte_535:
		.BYTE 0
byte_536:
		.BYTE 0
byte_537:
		.BYTE 0
_cheat_flag0:
		.BYTE 0
byte_539:
		.BYTE 0
byte_53A:
		.BYTE 0
byte_53B:
		.BYTE 0
byte_53C:
		.BYTE 0
byte_53D:
		.BYTE 0
byte_53E:
		.BYTE 0
byte_53F:
		.BYTE 0
byte_540:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_544:
		.BYTE 0
byte_545:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_549:
		.BYTE 0
byte_54A:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_54E:
		.BYTE 0
byte_54F:
		.BYTE 0
_ending_sub_idx:
		.BYTE 0
byte_551:
		.BYTE 0
		.BYTE 0
byte_553:
		.BYTE 0
byte_554:
		.BYTE 0
byte_555:
		.BYTE 0
byte_556:
		.BYTE 0
byte_557:
		.BYTE 0
byte_558:
		.BYTE 0
_match_idx:
		.BYTE 0
_game_mode_idx:
		.BYTE 0
byte_55B:
		.BYTE 0
byte_55C:
		.BYTE 0
byte_55D:
		.BYTE 0
_title_push_start_toggle:
		.BYTE 0
byte_55F:
		.BYTE 0
_match_pts_val:
		.BYTE 0,0
_main_sub_idx:
		.BYTE 0
byte_563:
		.BYTE 0
_demo_sub_idx:
		.BYTE 0
byte_565:
		.BYTE 0
byte_566:
		.BYTE 0
byte_567:
		.BYTE 0
byte_568:
		.BYTE 0
byte_569:
		.BYTE 0
byte_56A:
		.BYTE 0
byte_56B:
		.BYTE 0
		.BYTE 0
byte_56D:
		.BYTE 0
_1p_first_dice_roll_override:
		.BYTE 0
_2p_first_dice_roll_override:
		.BYTE 0
byte_570:
		.BYTE 0
byte_571:
		.BYTE 0
byte_572:
		.BYTE 0
byte_573:
		.BYTE 0
byte_574:
		.BYTE 0
byte_575:
		.BYTE 0
_chr_data_idx:
		.BYTE 0
byte_577:
		.BYTE 0
byte_578:
		.BYTE 0
byte_579:
		.BYTE 0
		.BYTE 0
byte_57B:
		.BYTE 0
_pal_buf4:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0
byte_59F:
		.BYTE 0
byte_5A0:
		.BYTE 0
byte_5A1:
		.BYTE 0
word_5A2:
		.BYTE 0,0
byte_5A4:
		.BYTE 0
byte_5A5:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
_training_mode_flag:
		.BYTE 0
byte_5B1:
		.BYTE 0
byte_5B2:
		.BYTE 0
byte_5B3:
		.BYTE 0
byte_5B4:
		.BYTE 0
byte_5B5:
		.BYTE 0
byte_5B6:
		.BYTE 0
byte_5B7:
		.BYTE 0
byte_5B8:
		.BYTE 0
byte_5B9:
		.BYTE 0
byte_5BA:
		.BYTE 0
byte_5BB:
		.BYTE 0
byte_5BC:
		.BYTE 0
byte_5BD:
		.BYTE 0
byte_5BE:
		.BYTE 0
byte_5BF:
		.BYTE 0
byte_5C0:
		.BYTE 0
byte_5C1:
		.BYTE 0
byte_5C2:
		.BYTE 0
byte_5C3:
		.BYTE 0
byte_5C4:
		.BYTE 0
byte_5C5:
		.BYTE 0
byte_5C6:
		.BYTE 0
byte_5C7:
		.BYTE 0
byte_5C8:
		.BYTE 0
byte_5C9:
		.BYTE 0
byte_5CA:
		.BYTE 0
byte_5CB:
		.BYTE 0
byte_5CC:
		.BYTE 0
byte_5CD:
		.BYTE 0
byte_5CE:
		.BYTE 0
byte_5CF:
		.BYTE 0
byte_5D0:
		.BYTE 0
byte_5D1:
		.BYTE 0
byte_5D2:
		.BYTE 0
byte_5D3:
		.BYTE 0
byte_5D4:
		.BYTE 0
byte_5D5:
		.BYTE 0
byte_5D6:
		.BYTE 0
byte_5D7:
		.BYTE 0
byte_5D8:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_5DC:
		.BYTE 0
byte_5DD:
		.BYTE 0
byte_5DE:
		.BYTE 0
byte_5DF:
		.BYTE 0
byte_5E0:
		.BYTE 0
byte_5E1:
		.BYTE 0
byte_5E2:
		.BYTE 0
		.BYTE 0
byte_5E4:
		.BYTE 0
		.BYTE 0
byte_5E6:
		.BYTE 0
byte_5E7:
		.BYTE 0
		.BYTE 0
byte_5E9:
		.BYTE 0
byte_5EA:
		.BYTE 0
byte_5EB:
		.BYTE 0
byte_5EC:
		.BYTE 0
byte_5ED:
		.BYTE 0
byte_5EE:
		.BYTE 0
		.BYTE 0
byte_5F0:
		.BYTE 0
byte_5F1:
		.BYTE 0
byte_5F2:
		.BYTE 0
byte_5F3:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0

		ORG $0600

byte_600:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0
_tlm_ramB1_buf:
		.BYTE 0
_nmi_tlmB1_ram:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
_ppu_queue_req:
		.BYTE 0
_ppu_queue_buf_pos:
		.BYTE 0
_ppu_queue_buf:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0
byte_700:
_cheat_flag1:
		.BYTE 0
_menu_pos_idx:
		.BYTE 0
_match_menu_pos:
		.BYTE 0
_cur_prg_bank:
		.BYTE 0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
		.BYTE 0,0,0,0,0,0,0,0,0,0,0,0
byte_720:
		.BYTE 0
byte_721:
		.BYTE 0
byte_722:
		.BYTE 0
byte_723:
		.BYTE 0
byte_724:
		.BYTE 0
byte_725:
		.BYTE 0
byte_726:
		.BYTE 0
byte_727:
		.BYTE 0
byte_728:
		.BYTE 0
byte_729:
		.BYTE 0
byte_72A:
		.BYTE 0
byte_72B:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_734:
		.BYTE 0
byte_735:
		.BYTE 0
byte_736:
		.BYTE 0
byte_737:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_73A:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_73E:
		.BYTE 0
byte_73F:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_742:
		.BYTE 0
byte_743:
		.BYTE 0
byte_744:
		.BYTE 0
byte_745:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_748:
		.BYTE 0
byte_749:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_74C:
		.BYTE 0
byte_74D:
		.BYTE 0
byte_74E:
		.BYTE 0
byte_74F:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_752:
		.BYTE 0
		.BYTE 0
byte_754:
		.BYTE 0
byte_755:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_75A:
		.BYTE 0
byte_75B:
		.BYTE 0
byte_75C:
		.BYTE 0
byte_75D:
		.BYTE 0
byte_75E:
		.BYTE 0
byte_75F:
		.BYTE 0
byte_760:
		.BYTE 0
byte_761:
		.BYTE 0
byte_762:
		.BYTE 0
byte_763:
		.BYTE 0
byte_764:
		.BYTE 0
byte_765:
		.BYTE 0
byte_766:
		.BYTE 0
byte_767:
		.BYTE 0
byte_768:
		.BYTE 0
byte_769:
		.BYTE 0
byte_76A:
		.BYTE 0
		.BYTE 0
byte_76C:
		.BYTE 0
		.BYTE 0
byte_76E:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_772:
		.BYTE 0
		.BYTE 0
byte_774:
		.BYTE 0
byte_775:
		.BYTE 0
byte_776:
		.BYTE 0
byte_777:
		.BYTE 0
		.BYTE 0
byte_779:
		.BYTE 0
byte_77A:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_77D:
		.BYTE 0
byte_77E:
		.BYTE 0
byte_77F:
		.BYTE 0
byte_780:
		.BYTE 0
byte_781:
		.BYTE 0
		.BYTE 0
byte_783:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_786:
		.BYTE 0
		.BYTE 0
byte_788:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_78B:
		.BYTE 0
		.BYTE 0
		.BYTE 0
byte_78E:
		.BYTE 0
byte_78F:
		.BYTE 0
byte_790:
		.BYTE 0
byte_791:
		.BYTE 0
byte_792:
		.BYTE 0
byte_793:
		.BYTE 0
byte_794:
		.BYTE 0
byte_795:
		.BYTE 0
byte_796:
		.BYTE 0
		.BYTE 0
byte_798:
		.BYTE 0
		.BYTE 0
byte_79A:
		.BYTE 0
		.BYTE 0
byte_79C:
		.BYTE 0
		.BYTE 0
byte_79E:
		.BYTE 0
		.BYTE 0
byte_7A0:
		.BYTE 0
byte_7A1:
		.BYTE 0
byte_7A2:
		.BYTE 0
byte_7A3:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
_apu_play_ctrlA:
		.BYTE 0
_apu_play_ctrlB:
		.BYTE 0
_apu_play_ctrlC:
		.BYTE 0
_apu_play_ctrlE:
		.BYTE 0
_apu_play_ctrlD:
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0
		.BYTE 0

;--------------------P-P-U----------------------

		ORG $2000

_PPU_CTRL:
		.BYTE 0
_PPU_MASK:
		.BYTE 0
_PPU_STATUS:
		.BYTE 0
_PPU_OAM_ADDR:
		.BYTE 0
_PPU_OAM_DATA:
		.BYTE 0
_PPU_SCROLL:
		.BYTE 0
_PPU_ADDR:
		.BYTE 0
_PPU_DATA:
		.BYTE 0

;--------------------A-P-U----------------------

		ORG $4000

_APU_PULSE1_ENV:
		.BYTE 0
_APU_PULSE1_SWEEP:
		.BYTE	0
_APU_PULSE1_TIME:
		.BYTE 0
_APU_PULSE1_LEN:
		.BYTE 0
_APU_PULSE2_ENV:
		.BYTE 0
_APU_PULSE2_SWEEP:
		.BYTE	0
_APU_PULSE2_TIME:
		.BYTE 0
_APU_PULSE2_LEN:
		.BYTE 0
_APU_TRI_COUNT:
		.BYTE 0
_APU_TRI_UNUSED:
		.BYTE 0
_APU_TRI_TIME:
		.BYTE 0
_APU_TRI_LEN:
		.BYTE 0
_APU_NOISE_ENV:
		.BYTE 0
_APU_NOISE_UNUSED:
		.BYTE 0
_APU_NOISE_LOOP:
		.BYTE 0
_APU_NOISE_LEN:
		.BYTE 0
_APU_DMC_FREQ:
		.BYTE 0
_APU_DMC_LOAD:
		.BYTE 0
_APU_DMC_ADDR:
		.BYTE 0
_APU_DMC_LEN:
		.BYTE 0
_PPU_OAM_DMA:
		.BYTE 0
_APU_STATUS:
		.BYTE 0
_PAD0_REG:
		.BYTE 0
_PAD1_REG:
		.BYTE 0
