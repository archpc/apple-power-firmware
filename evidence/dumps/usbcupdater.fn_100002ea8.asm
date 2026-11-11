[2K            ; CALL XREF from sym.func.100003a18 @ 0x100003a84
            ; CALL XREF from sym.func.1000041cc @ 0x100004978
/ sym.func.100002ea8(void *instance, int64_t arg2);
|           ; arg void *instance @ x0
|           ; arg int64_t arg2 @ x1
|           ; var int64_t var_438h @ stack - 0x438
|           ; var int64_t var_430h @ stack - 0x430
|           ; var int64_t var_428h @ stack - 0x428
|           ; var int64_t var_420h @ stack - 0x420
|           ; var int64_t var_3f0h @ stack - 0x3f0
|           ; var int64_t var_3e8h @ stack - 0x3e8
|           ; var int64_t var_3e0h @ stack - 0x3e0
|           ; var int64_t var_3b0h @ stack - 0x3b0
|           ; var int64_t var_3a8h @ stack - 0x3a8
|           ; var int64_t var_3a0h @ stack - 0x3a0
|           ; var int64_t var_370h @ stack - 0x370
|           ; var int64_t var_368h @ stack - 0x368
|           ; var int64_t var_360h @ stack - 0x360
|           ; var int64_t var_330h @ stack - 0x330
|           ; var int64_t var_328h @ stack - 0x328
|           ; var int64_t var_320h @ stack - 0x320
|           ; var int64_t var_2f0h @ stack - 0x2f0
|           ; var int64_t var_270h @ stack - 0x270
|           ; var int64_t var_1f0h @ stack - 0x1f0
|           ; var int64_t var_170h @ stack - 0x170
|           ; var int64_t var_60h @ stack - 0x60
|           ; var int64_t var_50h @ stack - 0x50
|           ; var int64_t var_40h @ stack - 0x40
|           ; var int64_t var_30h @ stack - 0x30
|           ; var int64_t var_20h @ stack - 0x20
|           ; var int64_t var_10h @ stack - 0x10
|           0x100002ea8      pacibsp
|           0x100002eac      stp   x28, x27, [var_60h]!
|           0x100002eb0      stp   x26, x25, [var_50h]
|           0x100002eb4      stp   x24, x23, [var_40h]
|           0x100002eb8      stp   x22, x21, [var_30h]
|           0x100002ebc      stp   x20, x19, [var_20h]
|           0x100002ec0      stp   x29, x30, [var_10h]
|           0x100002ec4      add   x29, sp, 0x50
|           0x100002ec8      sub   sp, sp, 0x3e0
|           0x100002ecc      mov   x20, x1                             ; arg2
|           0x100002ed0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100002ed4      ldr   x8, [x8, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x100002ed8      ldr   x8, [x8]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x100002edc      stur  x8, [var_60h]
|           0x100002ee0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100002ee4      mov   x19, x0
|           0x100002ee8      mov   x0, x20                             ; void *instance
|           0x100002eec      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100002ef0      mov   x28, x0
|           0x100002ef4      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
|           0x100002ef8      ldrb  w8, [x8, 0x178]                     ; [0x100010178:4]=0
|                                                                      ; section.13.__DATA.__common
|       ,=< 0x100002efc      tbz   w8, 0, 0x100002f94
|      .--> 0x100002f00      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|      :|   0x100002f04      add   x2, x2, 0x500                       ; 0x10000c500
|      :|                                                              ; reloc.__CFConstantStringClassReference.10000c500
|      :|   0x100002f08      mov   x0, x19
|      :|   0x100002f0c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      :|   0x100002f10      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      :|   0x100002f14      mov   x21, x0
|      :|   0x100002f18      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|      :|   0x100002f1c      add   x2, x2, 0x520                       ; 0x10000c520
|      :|                                                              ; reloc.__CFConstantStringClassReference.10000c520
|      :|   0x100002f20      mov   x0, x19
|      :|   0x100002f24      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      :|   0x100002f28      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      :|   0x100002f2c      mov   x22, x0
|      :|   0x100002f30      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|      :|   0x100002f34      add   x2, x2, 0x360                       ; 0x10000c360
|      :|                                                              ; reloc.__CFConstantStringClassReference.10000c360
|      :|   0x100002f38      mov   x0, x28
|      :|   0x100002f3c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      :|   0x100002f40      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      :|   0x100002f44      mov   x23, x0
|      :|   0x100002f48      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
|      :|   0x100002f4c      ldr   x24, [x24, 0xbf8]                   ; [0x10000cbf8:4]=0x1c160 ; "`\xc1\U00000001"
|     ,===< 0x100002f50      cbz   x0, 0x100002ff4
|    ,====< 0x100002f54      cbz   x21, 0x100003018
|    ||:|   0x100002f58      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|    ||:|   0x100002f5c      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|    ||:|   0x100002f60      bl    sym.imp.objc_opt_class
|    ||:|   0x100002f64      mov   x1, x0
|    ||:|   0x100002f68      mov   x0, x21
|    ||:|   0x100002f6c      bl    sym.imp.objc_opt_isKindOfClass
|   ,=====< 0x100002f70      tbz   w0, 0, 0x1000031f8
|   |||:|   0x100002f74      mov   x1, x21                             ; int64_t arg3
|   |||:|   0x100002f78      mov   x2, x23
|   |||:|   0x100002f7c      bl    sym.func.1000020e8
|  ,======< 0x100002f80      cbz   w0, 0x100003018
|  ||||:|   0x100002f84      ldr   x3, [x24]                           ; [0x10001c160:4]=0
|  ||||:|                                                              ; str.tubs
|  ||||:|   0x100002f88      adrp  x0, data.100007000                  ; 0x100007000
|  ||||:|   0x100002f8c      add   x0, x0, 0xddb                       ; 0x100007ddb ; "** Min firmware version not met.  Aborting\n"
| ,=======< 0x100002f90      b     0x100003054
| |||||:`-> 0x100002f94      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||:    0x100002f98      add   x22, x22, 0x360                     ; 0x10000c360
| |||||:                                                               ; reloc.__CFConstantStringClassReference.10000c360
| |||||:    0x100002f9c      mov   x0, x19
| |||||:    0x100002fa0      mov   x2, x22
| |||||:    0x100002fa4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||:    0x100002fa8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||:    0x100002fac      mov   x21, x0
| |||||:    0x100002fb0      mov   x0, x28
| |||||:    0x100002fb4      mov   x2, x22
| |||||:    0x100002fb8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||:    0x100002fbc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||:    0x100002fc0      mov   x22, x0
| |||||:,=< 0x100002fc4      cbz   x21, 0x100003230
| ========< 0x100002fc8      cbz   x22, 0x100003230
| |||||:|   0x100002fcc      mov   x1, x21                             ; int64_t arg3
| |||||:|   0x100002fd0      mov   x2, x22
| |||||:|   0x100002fd4      bl    sym.func.1000020e8
| |||||:|   0x100002fd8      mov   x23, x0
| |||||:|   0x100002fdc      mov   x0, x22                             ; void *instance
| |||||:|   0x100002fe0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100002fe4      mov   x0, x21                             ; void *instance
| |||||:|   0x100002fe8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||`==< 0x100002fec      cbnz  w23, 0x100002f00
| |||||,==< 0x100002ff0      b     0x1000035cc
| ||||`---> 0x100002ff4      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| |||| ||                                                              ; str.tubs ; FILE *stream
| |||| ||   0x100002ff8      adrp  x0, data.100007000                  ; 0x100007000
| |||| ||   0x100002ffc      add   x0, x0, 0xd8c                       ; 0x100007d8c ; "** No current firmware version?\n" ; const void *ptr
| |||| ||   0x100003000      mov   w1, 0x20
| |||| ||   0x100003004      mov   w2, 1
| |||| ||   0x100003008      bl    sym.imp.fwrite                      ; size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
| |||| ||   0x10000300c      ldr   x0, [x24]                           ; [0x10001c160:4]=0
| |||| ||                                                              ; str.tubs ; FILE *stream
| |||| ||   0x100003010      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| ||||,===< 0x100003014      b     0x10000305c
| =`-`----> 0x100003018      cbz   x22, 0x10000305c
| | | |||   0x10000301c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | | |||   0x100003020      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| | | |||   0x100003024      bl    sym.imp.objc_opt_class
| | | |||   0x100003028      mov   x1, x0
| | | |||   0x10000302c      mov   x0, x22
| | | |||   0x100003030      bl    sym.imp.objc_opt_isKindOfClass
| | |,====< 0x100003034      tbz   w0, 0, 0x100003208
| | |||||   0x100003038      mov   x1, x22                             ; int64_t arg3
| | |||||   0x10000303c      mov   x2, x23
| | |||||   0x100003040      bl    sym.func.100002044
| |,======< 0x100003044      cbz   w0, 0x10000305c
| |||||||   0x100003048      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| |||||||                                                              ; str.tubs
| |||||||   0x10000304c      adrp  x0, data.100007000                  ; 0x100007000
| |||||||   0x100003050      add   x0, x0, 0xe35                       ; 0x100007e35 ; "** Max firmware version not met.  Aborting\n"
| |||||||   ; CODE XREF from sym.func.100002ea8 @ 0x100002f90
| `-------> 0x100003054      mov   w1, 0x2b                            ; '+'
| ,=======< 0x100003058      b     0x100003218
| |||||||   ; CODE XREF from sym.func.100002ea8 @ 0x100003014
| -`--`---> 0x10000305c      mov   x0, x23                             ; void *instance
| | || ||   0x100003060      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | || ||   0x100003064      mov   x0, x22                             ; void *instance
| | || ||   0x100003068      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | || ||   0x10000306c      mov   x0, x21                             ; void *instance
| | || ||   0x100003070      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | || ||   0x100003074      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| | || ||   0x100003078      add   x22, x22, 0x180                     ; 0x10000c180
| | || ||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| | || ||   0x10000307c      mov   x0, x19
| | || ||   0x100003080      mov   x2, x22
| | || ||   0x100003084      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| | || ||   0x100003088      bl    sym.imp.objc_claimAutoreleasedReturnValue
| | || ||   0x10000308c      mov   x21, x0
| | || ||   0x100003090      mov   x0, x28
| | || ||   0x100003094      mov   x2, x22
| | || ||   0x100003098      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| | || ||   0x10000309c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| | || ||   0x1000030a0      mov   x22, x0
| | ||,===< 0x1000030a4      cbz   x21, 0x1000030c4
| |,======< 0x1000030a8      cbnz  x22, 0x1000030c4
| --------> 0x1000030ac      mov   x25, 0
| |||||||   0x1000030b0      mov   x23, 0
| |||||||   ; CODE XREF from sym.func.100002ea8 @ 0x100003590
| --------> 0x1000030b4      mov   x0, x22                             ; void *instance
| |||||||   0x1000030b8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x1000030bc      mov   x0, x25
| ========< 0x1000030c0      b     0x1000035b8
| =`--`---> 0x1000030c4      cbz   x21, 0x100003238
| | || ||   0x1000030c8      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
| | || ||   0x1000030cc      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| | || ||   0x1000030d0      bl    sym.imp.objc_opt_class
| | || ||   0x1000030d4      mov   x1, x0
| | || ||   0x1000030d8      mov   x0, x21
| | || ||   0x1000030dc      bl    sym.imp.objc_opt_isKindOfClass
| | ||,===< 0x1000030e0      tbnz  w0, 0, 0x100003100
| | |||||   0x1000030e4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | |||||   0x1000030e8      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| | |||||   0x1000030ec      bl    sym.imp.objc_opt_class
| | |||||   0x1000030f0      mov   x1, x0
| | |||||   0x1000030f4      mov   x0, x21
| | |||||   0x1000030f8      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000030fc      tbz   w0, 0, 0x1000030ac
| | ||`---> 0x100003100      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| | || ||   0x100003104      bl    sym.imp.objc_opt_class
| | || ||   0x100003108      mov   x1, x0
| | || ||   0x10000310c      mov   x0, x21
| | || ||   0x100003110      bl    sym.imp.objc_opt_isKindOfClass
| | || ||   0x100003114      mov   x24, x0
| | || ||   0x100003118      mov   x0, x21                             ; void *instance
| | || ||   0x10000311c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| | || ||   0x100003120      mov   x23, x0
| | ||,===< 0x100003124      tbz   w24, 0, 0x100003244
| | |||||   0x100003128      movi  v0.2d, 0000000000000000
| | |||||   0x10000312c      stp   q0, q0, [var_320h + 0x10]
| | |||||   0x100003130      stp   q0, q0, [var_330h]
| | |||||   0x100003134      add   x2, var_330h
| | |||||   0x100003138      sub   x3, var_10h + 0xf0
| | |||||   0x10000313c      mov   x0, x23
| | |||||   0x100003140      mov   w4, 0x10
| | |||||   0x100003144      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |,======< 0x100003148      cbz   x0, 0x10000358c
| |||||||   0x10000314c      mov   x24, x0
| |||||||   0x100003150      str   x28, [var_438h]
| |||||||   0x100003154      mov   w27, 0
| |||||||   0x100003158      mov   x25, 0
| |||||||   0x10000315c      ldr   x8, [var_320h]                      ; [0x120:4]=-1 ; 288
| |||||||   0x100003160      ldr   x28, [x8]
| --------> 0x100003164      mov   x20, 0
| |||||||   0x100003168      mov   x26, x25
| --------> 0x10000316c      ldr   x8, [var_320h]                      ; [0x120:4]=-1 ; 288
| |||||||   0x100003170      ldr   x8, [x8]
| |||||||   0x100003174      cmp   x8, x28
| ========< 0x100003178      b.eq  0x100003184
| |||||||   0x10000317c      mov   x0, x23                             ; void *instance
| |||||||   0x100003180      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100003184      ldr   x8, [var_328h]                      ; [0x118:4]=-1 ; 280
| |||||||   0x100003188      ldr   x0, [x8, x20, lsl 3]                ; void *instance
| |||||||   0x10000318c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100003190      mov   x25, x0
| |||||||   0x100003194      mov   x0, x26                             ; void *instance
| |||||||   0x100003198      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x10000319c      mov   x1, x25                             ; int64_t arg3
| |||||||   0x1000031a0      mov   x2, x22
| |||||||   0x1000031a4      bl    sym.func.100001fa0
| |||||||   0x1000031a8      orr   w27, w27, w0
| |||||||   0x1000031ac      add   x20, x20, 1
| |||||||   0x1000031b0      mov   x26, x25
| |||||||   0x1000031b4      subs  x24, x24, 1
| ========< 0x1000031b8      b.ne  0x10000316c
| |||||||   0x1000031bc      add   x2, var_330h
| |||||||   0x1000031c0      sub   x3, var_10h + 0xf0
| |||||||   0x1000031c4      mov   x0, x23
| |||||||   0x1000031c8      mov   w4, 0x10
| |||||||   0x1000031cc      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x1000031d0      mov   x24, x0
| ========< 0x1000031d4      cbnz  x0, 0x100003164
| |||||||   0x1000031d8      mov   x0, x25                             ; void *instance
| |||||||   0x1000031dc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x1000031e0      mov   x26, 0
| |||||||   0x1000031e4      mov   x25, 0
| |||||||   0x1000031e8      mov   x24, x23
| |||||||   0x1000031ec      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
| ========< 0x1000031f0      tbz   w27, 0, 0x1000030b4
| ========< 0x1000031f4      b     0x100003264
| ||`-----> 0x1000031f8      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| || ||||                                                              ; str.tubs
| || ||||   0x1000031fc      adrp  x0, data.100007000                  ; 0x100007000
| || ||||   0x100003200      add   x0, x0, 0xdad                       ; 0x100007dad ; "** minversion bad object type in personality\n"
| ||,=====< 0x100003204      b     0x100003214
| |||`----> 0x100003208      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| ||| |||                                                              ; str.tubs
| ||| |||   0x10000320c      adrp  x0, data.100007000                  ; 0x100007000
| ||| |||   0x100003210      add   x0, x0, 0xe07                       ; 0x100007e07 ; "** maxversion bad object type in personality\n"
| ||| |||   ; CODE XREF from sym.func.100002ea8 @ 0x100003204
| ||`-----> 0x100003214      mov   w1, 0x2d                            ; '-'
| ||  |||   ; CODE XREF from sym.func.100002ea8 @ 0x100003058
| `-------> 0x100003218      mov   w2, 1
|  |  |||   0x10000321c      bl    sym.imp.fwrite                      ; size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
|  |  |||   0x100003220      ldr   x0, [x24]                           ; [0x10001c160:4]=0
|  |  |||                                                              ; str.tubs ; FILE *stream
|  |  |||   0x100003224      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  |  |||   0x100003228      mov   x0, x23                             ; void *instance
|  |  |||   0x10000322c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ------`-> 0x100003230      mov   x0, x22
|  |  ||,=< 0x100003234      b     0x1000035c0
| --------> 0x100003238      mov   x26, 0
|  |  |||   0x10000323c      mov   x24, 0
|  | ,====< 0x100003240      b     0x100003264
|  | |`---> 0x100003244      mov   x1, x23                             ; int64_t arg3
|  | | ||   0x100003248      mov   x2, x22
|  | | ||   0x10000324c      bl    sym.func.100001fa0
|  | | ||   0x100003250      mov   x24, 0
|  | | ||   0x100003254      mov   x26, x23
|  | | ||   0x100003258      mov   x25, x23
|  | | ||   0x10000325c      mov   x23, 0
| ========< 0x100003260      cbz   w0, 0x1000030b4
|  | | ||   ; CODE XREFS from sym.func.100002ea8 @ 0x1000031f4, 0x100003240
| ---`----> 0x100003264      mov   x0, x22                             ; void *instance
|  |   ||   0x100003268      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |   ||   0x10000326c      mov   x0, x26                             ; void *instance
|  |   ||   0x100003270      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |   ||   0x100003274      mov   x0, x24                             ; void *instance
|  |   ||   0x100003278      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |   ||   0x10000327c      mov   x0, x21                             ; void *instance
|  |   ||   0x100003280      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |   ||   0x100003284      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|  |   ||   0x100003288      add   x22, x22, 0x1e0                     ; 0x10000c1e0
|  |   ||                                                              ; reloc.__CFConstantStringClassReference.10000c1e0
|  |   ||   0x10000328c      mov   x0, x19
|  |   ||   0x100003290      mov   x2, x22
|  |   ||   0x100003294      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  |   ||   0x100003298      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |   ||   0x10000329c      mov   x21, x0
|  |   ||   0x1000032a0      mov   x0, x28
|  |   ||   0x1000032a4      mov   x2, x22
|  |   ||   0x1000032a8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  |   ||   0x1000032ac      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |   ||   0x1000032b0      mov   x22, x0
|  |   ||   0x1000032b4      mov   x24, 0
|  |   ||   0x1000032b8      mov   x23, 0
|  |  ,===< 0x1000032bc      cbz   x21, 0x1000035ac
|  | ,====< 0x1000032c0      cbz   x22, 0x1000035ac
|  | ||||   0x1000032c4      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
|  | ||||   0x1000032c8      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  | ||||   0x1000032cc      bl    sym.imp.objc_opt_class
|  | ||||   0x1000032d0      mov   x1, x0
|  | ||||   0x1000032d4      mov   x0, x21
|  | ||||   0x1000032d8      bl    sym.imp.objc_opt_isKindOfClass
|  |,=====< 0x1000032dc      tbnz  w0, 0, 0x1000032fc
|  ||||||   0x1000032e0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||||||   0x1000032e4      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|  ||||||   0x1000032e8      bl    sym.imp.objc_opt_class
|  ||||||   0x1000032ec      mov   x1, x0
|  ||||||   0x1000032f0      mov   x0, x21
|  ||||||   0x1000032f4      bl    sym.imp.objc_opt_isKindOfClass
| ,=======< 0x1000032f8      tbz   w0, 0, 0x100003594
| ||`-----> 0x1000032fc      str   x28, [var_438h]
| || ||||   0x100003300      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| || ||||   0x100003304      bl    sym.imp.objc_opt_class
| || ||||   0x100003308      mov   x1, x0
| || ||||   0x10000330c      mov   x0, x21
| || ||||   0x100003310      bl    sym.imp.objc_opt_isKindOfClass
| || ||||   0x100003314      mov   x24, x0
| || ||||   0x100003318      mov   x0, x21                             ; void *instance
| || ||||   0x10000331c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| || ||||   0x100003320      mov   x23, x0
| ||,=====< 0x100003324      tbz   w24, 0, 0x1000033ec
| |||||||   0x100003328      movi  v0.2d, 0000000000000000
| |||||||   0x10000332c      stp   q0, q0, [var_360h + 0x10]
| |||||||   0x100003330      stp   q0, q0, [var_370h]
| |||||||   0x100003334      add   x2, var_370h
| |||||||   0x100003338      add   x3, var_170h
| |||||||   0x10000333c      mov   x0, x23
| |||||||   0x100003340      mov   w4, 0x10
| |||||||   0x100003344      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x100003348      mov   x24, x0
| ========< 0x10000334c      cbz   x0, 0x1000035a8
| |||||||   0x100003350      mov   x25, 0
| |||||||   0x100003354      mov   w28, 0
| |||||||   0x100003358      ldr   x8, [var_360h]                      ; [0xe0:4]=-1 ; 224
| |||||||   0x10000335c      ldr   x27, [x8]
| --------> 0x100003360      mov   x20, 0
| |||||||   0x100003364      mov   x26, x25
| --------> 0x100003368      ldr   x8, [var_360h]                      ; [0xe0:4]=-1 ; 224
| |||||||   0x10000336c      ldr   x8, [x8]
| |||||||   0x100003370      cmp   x8, x27
| ========< 0x100003374      b.eq  0x100003380
| |||||||   0x100003378      mov   x0, x23                             ; void *instance
| |||||||   0x10000337c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100003380      ldr   x8, [var_368h]                      ; [0xd8:4]=-1 ; 216
| |||||||   0x100003384      ldr   x0, [x8, x20, lsl 3]                ; void *instance
| |||||||   0x100003388      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x10000338c      mov   x25, x0
| |||||||   0x100003390      mov   x0, x26                             ; void *instance
| |||||||   0x100003394      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003398      mov   x1, x25                             ; int64_t arg3
| |||||||   0x10000339c      mov   x2, x22
| |||||||   0x1000033a0      bl    sym.func.100001fa0
| |||||||   0x1000033a4      orr   w28, w28, w0
| |||||||   0x1000033a8      add   x20, x20, 1
| |||||||   0x1000033ac      mov   x26, x25
| |||||||   0x1000033b0      subs  x24, x24, 1
| ========< 0x1000033b4      b.ne  0x100003368
| |||||||   0x1000033b8      add   x2, var_370h
| |||||||   0x1000033bc      add   x3, var_170h
| |||||||   0x1000033c0      mov   x0, x23
| |||||||   0x1000033c4      mov   w4, 0x10
| |||||||   0x1000033c8      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x1000033cc      mov   x24, x0
| ========< 0x1000033d0      cbnz  x0, 0x100003360
| |||||||   0x1000033d4      mov   x0, x25                             ; void *instance
| |||||||   0x1000033d8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x1000033dc      mov   x25, x23
| |||||||   0x1000033e0      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
| ========< 0x1000033e4      tbnz  w28, 0, 0x100003404
| ========< 0x1000033e8      b     0x1000035a8
| ||`-----> 0x1000033ec      mov   x1, x23                             ; int64_t arg3
| || ||||   0x1000033f0      mov   x2, x22
| || ||||   0x1000033f4      bl    sym.func.100001fa0
| || ||||   0x1000033f8      mov   x25, 0
| || ||||   0x1000033fc      mov   x24, x23
| ||,=====< 0x100003400      cbz   w0, 0x1000035a0
| --------> 0x100003404      mov   x0, x22                             ; void *instance
| |||||||   0x100003408      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x10000340c      mov   x0, x24                             ; void *instance
| |||||||   0x100003410      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003414      mov   x0, x25                             ; void *instance
| |||||||   0x100003418      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x10000341c      mov   x0, x23                             ; void *instance
| |||||||   0x100003420      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003424      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||||   0x100003428      add   x22, x22, 0x220                     ; 0x10000c220
| |||||||                                                              ; reloc.__CFConstantStringClassReference.10000c220
| |||||||   0x10000342c      mov   x0, x19
| |||||||   0x100003430      mov   x2, x22
| |||||||   0x100003434      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||||   0x100003438      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||||   0x10000343c      mov   x21, x0
| |||||||   0x100003440      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
| |||||||   0x100003444      mov   x0, x28
| |||||||   0x100003448      mov   x2, x22
| |||||||   0x10000344c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||||   0x100003450      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||||   0x100003454      mov   x22, x0
| |||||||   0x100003458      mov   x24, 0
| |||||||   0x10000345c      mov   x25, 0
| ========< 0x100003460      cbz   x21, 0x100003860
| ========< 0x100003464      cbz   x22, 0x100003860
| |||||||   0x100003468      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |||||||   0x10000346c      bl    sym.imp.objc_opt_class
| |||||||   0x100003470      mov   x1, x0
| |||||||   0x100003474      mov   x0, x21
| |||||||   0x100003478      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x10000347c      tbnz  w0, 0, 0x10000349c
| |||||||   0x100003480      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||||||   0x100003484      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||||||   0x100003488      bl    sym.imp.objc_opt_class
| |||||||   0x10000348c      mov   x1, x0
| |||||||   0x100003490      mov   x0, x21
| |||||||   0x100003494      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100003498      tbz   w0, 0, 0x1000037bc
| --------> 0x10000349c      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |||||||   0x1000034a0      bl    sym.imp.objc_opt_class
| |||||||   0x1000034a4      mov   x1, x0
| |||||||   0x1000034a8      mov   x0, x21
| |||||||   0x1000034ac      bl    sym.imp.objc_opt_isKindOfClass
| |||||||   0x1000034b0      mov   x24, x0
| |||||||   0x1000034b4      mov   x0, x21                             ; void *instance
| |||||||   0x1000034b8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x1000034bc      mov   x23, x0
| ========< 0x1000034c0      tbz   w24, 0, 0x10000361c
| |||||||   0x1000034c4      movi  v0.2d, 0000000000000000
| |||||||   0x1000034c8      stp   q0, q0, [var_3a0h + 0x10]
| |||||||   0x1000034cc      stp   q0, q0, [var_3b0h]
| |||||||   0x1000034d0      add   x2, var_3b0h
| |||||||   0x1000034d4      add   x3, var_1f0h
| |||||||   0x1000034d8      mov   x0, x23
| |||||||   0x1000034dc      mov   w4, 0x10
| |||||||   0x1000034e0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x1000034e4      cbz   x0, 0x1000037c8
| |||||||   0x1000034e8      mov   x24, x0
| |||||||   0x1000034ec      mov   x25, 0
| |||||||   0x1000034f0      mov   w28, 0
| |||||||   0x1000034f4      ldr   x8, [var_3a0h]                      ; [0xa0:4]=-1 ; 160
| |||||||   0x1000034f8      ldr   x27, [x8]
| --------> 0x1000034fc      mov   x20, 0
| |||||||   0x100003500      mov   x26, x25
| --------> 0x100003504      ldr   x8, [var_3a0h]                      ; [0xa0:4]=-1 ; 160
| |||||||   0x100003508      ldr   x8, [x8]
| |||||||   0x10000350c      cmp   x8, x27
| ========< 0x100003510      b.eq  0x10000351c
| |||||||   0x100003514      mov   x0, x23                             ; void *instance
| |||||||   0x100003518      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x10000351c      ldr   x8, [var_3a8h]                      ; [0x98:4]=-1 ; 152
| |||||||   0x100003520      ldr   x0, [x8, x20, lsl 3]                ; void *instance
| |||||||   0x100003524      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100003528      mov   x25, x0
| |||||||   0x10000352c      mov   x0, x26                             ; void *instance
| |||||||   0x100003530      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003534      mov   x1, x25                             ; int64_t arg3
| |||||||   0x100003538      mov   x2, x22
| |||||||   0x10000353c      bl    sym.func.100001fa0
| |||||||   0x100003540      orr   w28, w28, w0
| |||||||   0x100003544      add   x20, x20, 1
| |||||||   0x100003548      mov   x26, x25
| |||||||   0x10000354c      subs  x24, x24, 1
| ========< 0x100003550      b.ne  0x100003504
| |||||||   0x100003554      add   x2, var_3b0h
| |||||||   0x100003558      add   x3, var_1f0h
| |||||||   0x10000355c      mov   x0, x23
| |||||||   0x100003560      mov   w4, 0x10
| |||||||   0x100003564      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x100003568      mov   x24, x0
| ========< 0x10000356c      cbnz  x0, 0x1000034fc
| |||||||   0x100003570      mov   x0, x25                             ; void *instance
| |||||||   0x100003574      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003578      mov   x25, 0
| |||||||   0x10000357c      mov   x24, x23
| |||||||   0x100003580      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
| ========< 0x100003584      tbnz  w28, 0, 0x100003634
| ========< 0x100003588      b     0x1000037cc
| |`------> 0x10000358c      mov   x25, 0
| ========< 0x100003590      b     0x1000030b4
| `-------> 0x100003594      mov   x24, 0
|   |||||   0x100003598      mov   x23, 0
|  ,======< 0x10000359c      b     0x1000035ac
|  |`-----> 0x1000035a0      mov   x24, x23
|  | ||||   0x1000035a4      mov   x23, x25
|  | ||||   ; CODE XREF from sym.func.100002ea8 @ 0x1000033e8
| --------> 0x1000035a8      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
|  | ||||   ; CODE XREF from sym.func.100002ea8 @ 0x10000359c
|  `-``---> 0x1000035ac      mov   x0, x22                             ; void *instance
|      ||   0x1000035b0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|      ||   0x1000035b4      mov   x0, x24
|      ||   ; CODE XREF from sym.func.100002ea8 @ 0x1000030c0
| --------> 0x1000035b8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|      ||   0x1000035bc      mov   x0, x23
|      ||   ; CODE XREFS from sym.func.100002ea8 @ 0x100003234, 0x100003874
|     .-`-> 0x1000035c0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     :|    0x1000035c4      mov   x0, x21                             ; void *instance
|     :|    0x1000035c8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     :|    ; CODE XREF from sym.func.100002ea8 @ 0x100002ff0
|     :`--> 0x1000035cc      mov   w24, 0
|     :     ; CODE XREF from sym.func.100002ea8 @ 0x100003a10
|     : .-> 0x1000035d0      mov   x0, x28                             ; void *instance
|     : :   0x1000035d4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     : :   0x1000035d8      mov   x0, x19                             ; void *instance
|     : :   0x1000035dc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     : :   0x1000035e0      ldur  x8, [var_60h]
|     : :   0x1000035e4      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
|     : :   0x1000035e8      ldr   x9, [x9, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|     : :   0x1000035ec      ldr   x9, [x9]                            ; [0x10001c158:4]=0
|     : :                                                              ; str.objc_stubs
|     : :   0x1000035f0      cmp   x9, x8
|     :,==< 0x1000035f4      b.ne  0x100003a14
|     :|:   0x1000035f8      mov   x0, x24
|     :|:   0x1000035fc      add   sp, sp, 0x3e0
|     :|:   0x100003600      ldp   x29, x30, [var_10h]
|     :|:   0x100003604      ldp   x20, x19, [var_20h]
|     :|:   0x100003608      ldp   x22, x21, [var_30h]
|     :|:   0x10000360c      ldp   x24, x23, [var_40h]
|     :|:   0x100003610      ldp   x26, x25, [var_50h]
|     :|:   0x100003614      ldp   x28, x27, [sp], 0x60
|     :|:   0x100003618      retab
| --------> 0x10000361c      mov   x1, x23                             ; int64_t arg3
|     :|:   0x100003620      mov   x2, x22
|     :|:   0x100003624      bl    sym.func.100001fa0
|     :|:   0x100003628      mov   x24, 0
|     :|:   0x10000362c      mov   x25, x23
|    ,====< 0x100003630      cbz   w0, 0x100003858
| --------> 0x100003634      mov   x0, x22                             ; void *instance
|    |:|:   0x100003638      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    |:|:   0x10000363c      mov   x0, x25                             ; void *instance
|    |:|:   0x100003640      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    |:|:   0x100003644      mov   x0, x24                             ; void *instance
|    |:|:   0x100003648      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    |:|:   0x10000364c      mov   x0, x23                             ; void *instance
|    |:|:   0x100003650      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    |:|:   0x100003654      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|    |:|:   0x100003658      add   x22, x22, 0x260                     ; 0x10000c260
|    |:|:                                                              ; reloc.__CFConstantStringClassReference.10000c260
|    |:|:   0x10000365c      mov   x0, x19
|    |:|:   0x100003660      mov   x2, x22
|    |:|:   0x100003664      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|    |:|:   0x100003668      bl    sym.imp.objc_claimAutoreleasedReturnValue
|    |:|:   0x10000366c      mov   x21, x0
|    |:|:   0x100003670      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
|    |:|:   0x100003674      mov   x0, x28
|    |:|:   0x100003678      mov   x2, x22
|    |:|:   0x10000367c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|    |:|:   0x100003680      bl    sym.imp.objc_claimAutoreleasedReturnValue
|    |:|:   0x100003684      mov   x22, x0
|    |:|:   0x100003688      mov   x24, 0
|    |:|:   0x10000368c      mov   x25, 0
|   ,=====< 0x100003690      cbz   x21, 0x100003860
|  ,======< 0x100003694      cbz   x22, 0x100003860
|  |||:|:   0x100003698      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  |||:|:   0x10000369c      bl    sym.imp.objc_opt_class
|  |||:|:   0x1000036a0      mov   x1, x0
|  |||:|:   0x1000036a4      mov   x0, x21
|  |||:|:   0x1000036a8      bl    sym.imp.objc_opt_isKindOfClass
| ,=======< 0x1000036ac      tbnz  w0, 0, 0x1000036cc
| ||||:|:   0x1000036b0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||||:|:   0x1000036b4      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||||:|:   0x1000036b8      bl    sym.imp.objc_opt_class
| ||||:|:   0x1000036bc      mov   x1, x0
| ||||:|:   0x1000036c0      mov   x0, x21
| ||||:|:   0x1000036c4      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000036c8      tbz   w0, 0, 0x1000037bc
| `-------> 0x1000036cc      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  |||:|:   0x1000036d0      bl    sym.imp.objc_opt_class
|  |||:|:   0x1000036d4      mov   x1, x0
|  |||:|:   0x1000036d8      mov   x0, x21
|  |||:|:   0x1000036dc      bl    sym.imp.objc_opt_isKindOfClass
|  |||:|:   0x1000036e0      mov   x24, x0
|  |||:|:   0x1000036e4      mov   x0, x21                             ; void *instance
|  |||:|:   0x1000036e8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  |||:|:   0x1000036ec      mov   x23, x0
| ,=======< 0x1000036f0      tbz   w24, 0, 0x1000037d4
| ||||:|:   0x1000036f4      movi  v0.2d, 0000000000000000
| ||||:|:   0x1000036f8      stp   q0, q0, [var_3e0h + 0x10]
| ||||:|:   0x1000036fc      stp   q0, q0, [var_3f0h]
| ||||:|:   0x100003700      add   x2, var_3f0h
| ||||:|:   0x100003704      add   x3, var_270h
| ||||:|:   0x100003708      mov   x0, x23
| ||||:|:   0x10000370c      mov   w4, 0x10
| ||||:|:   0x100003710      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x100003714      cbz   x0, 0x1000037c8
| ||||:|:   0x100003718      mov   x24, x0
| ||||:|:   0x10000371c      mov   x25, 0
| ||||:|:   0x100003720      mov   w28, 0
| ||||:|:   0x100003724      ldr   x8, [var_3e0h]                      ; [0x60:4]=-1 ; 96
| ||||:|:   0x100003728      ldr   x27, [x8]
| --------> 0x10000372c      mov   x20, 0
| ||||:|:   0x100003730      mov   x26, x25
| --------> 0x100003734      ldr   x8, [var_3e0h]                      ; [0x60:4]=-1 ; 96
| ||||:|:   0x100003738      ldr   x8, [x8]
| ||||:|:   0x10000373c      cmp   x8, x27
| ========< 0x100003740      b.eq  0x10000374c
| ||||:|:   0x100003744      mov   x0, x23                             ; void *instance
| ||||:|:   0x100003748      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x10000374c      ldr   x8, [var_3e8h]                      ; [0x58:4]=-1 ; 88
| ||||:|:   0x100003750      ldr   x0, [x8, x20, lsl 3]                ; void *instance
| ||||:|:   0x100003754      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ||||:|:   0x100003758      mov   x25, x0
| ||||:|:   0x10000375c      mov   x0, x26                             ; void *instance
| ||||:|:   0x100003760      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||||:|:   0x100003764      mov   x1, x25                             ; int64_t arg3
| ||||:|:   0x100003768      mov   x2, x22
| ||||:|:   0x10000376c      bl    sym.func.100001fa0
| ||||:|:   0x100003770      orr   w28, w28, w0
| ||||:|:   0x100003774      add   x20, x20, 1
| ||||:|:   0x100003778      mov   x26, x25
| ||||:|:   0x10000377c      subs  x24, x24, 1
| ========< 0x100003780      b.ne  0x100003734
| ||||:|:   0x100003784      add   x2, var_3f0h
| ||||:|:   0x100003788      add   x3, var_270h
| ||||:|:   0x10000378c      mov   x0, x23
| ||||:|:   0x100003790      mov   w4, 0x10
| ||||:|:   0x100003794      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ||||:|:   0x100003798      mov   x24, x0
| ========< 0x10000379c      cbnz  x0, 0x10000372c
| ||||:|:   0x1000037a0      mov   x0, x25                             ; void *instance
| ||||:|:   0x1000037a4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||||:|:   0x1000037a8      mov   x25, 0
| ||||:|:   0x1000037ac      mov   x24, x23
| ||||:|:   0x1000037b0      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
| ========< 0x1000037b4      tbz   w28, 0, 0x1000037cc
| ========< 0x1000037b8      b     0x1000037ec
| --------> 0x1000037bc      mov   x24, 0
| ||||:|:   0x1000037c0      mov   x25, 0
| ========< 0x1000037c4      b     0x100003860
| --------> 0x1000037c8      mov   x25, 0
| ||||:|:   ; CODE XREF from sym.func.100002ea8 @ 0x100003588
| --------> 0x1000037cc      mov   x24, x23
| ========< 0x1000037d0      b     0x10000385c
| `-------> 0x1000037d4      mov   x1, x23                             ; int64_t arg3
|  |||:|:   0x1000037d8      mov   x2, x22
|  |||:|:   0x1000037dc      bl    sym.func.100001fa0
|  |||:|:   0x1000037e0      mov   x24, 0
|  |||:|:   0x1000037e4      mov   x25, x23
| ,=======< 0x1000037e8      cbz   w0, 0x100003858
| ||||:|:   ; CODE XREF from sym.func.100002ea8 @ 0x1000037b8
| --------> 0x1000037ec      mov   x0, x22                             ; void *instance
| ||||:|:   0x1000037f0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||||:|:   0x1000037f4      mov   x0, x25                             ; void *instance
| ||||:|:   0x1000037f8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||||:|:   0x1000037fc      mov   x0, x24                             ; void *instance
| ||||:|:   0x100003800      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||||:|:   0x100003804      mov   x0, x23                             ; void *instance
| ||||:|:   0x100003808      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||||:|:   0x10000380c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| ||||:|:   0x100003810      add   x22, x22, 0x300                     ; 0x10000c300
| ||||:|:                                                              ; reloc.__CFConstantStringClassReference.10000c300
| ||||:|:   0x100003814      mov   x0, x19
| ||||:|:   0x100003818      mov   x2, x22
| ||||:|:   0x10000381c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| ||||:|:   0x100003820      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||||:|:   0x100003824      mov   x21, x0
| ||||:|:   0x100003828      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
| ||||:|:   0x10000382c      mov   x0, x28
| ||||:|:   0x100003830      mov   x2, x22
| ||||:|:   0x100003834      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| ||||:|:   0x100003838      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||||:|:   0x10000383c      mov   x22, x0
| ========< 0x100003840      cbz   x21, 0x100003878
| ========< 0x100003844      cbnz  x22, 0x100003878
| --------> 0x100003848      mov   w24, 0
| ||||:|:   0x10000384c      mov   x25, 0
| ||||:|:   0x100003850      mov   x26, 0
| ========< 0x100003854      b     0x1000039f0
| `--`----> 0x100003858      mov   x25, x23
|  || :|:   ; CODE XREF from sym.func.100002ea8 @ 0x1000037d0
| --------> 0x10000385c      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
|  || :|:   ; CODE XREF from sym.func.100002ea8 @ 0x1000037c4
| -``-----> 0x100003860      mov   x0, x22                             ; void *instance
|     :|:   0x100003864      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     :|:   0x100003868      mov   x0, x25                             ; void *instance
|     :|:   0x10000386c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     :|:   0x100003870      mov   x0, x24
|     `===< 0x100003874      b     0x1000035c0
| ----,===< 0x100003878      cbz   x21, 0x1000039a0
|     ||:   0x10000387c      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|     ||:   0x100003880      bl    sym.imp.objc_opt_class
|     ||:   0x100003884      mov   x1, x0
|     ||:   0x100003888      mov   x0, x21
|     ||:   0x10000388c      bl    sym.imp.objc_opt_isKindOfClass
|    ,====< 0x100003890      tbnz  w0, 0, 0x1000038b0
|    |||:   0x100003894      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|    |||:   0x100003898      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|    |||:   0x10000389c      bl    sym.imp.objc_opt_class
|    |||:   0x1000038a0      mov   x1, x0
|    |||:   0x1000038a4      mov   x0, x21
|    |||:   0x1000038a8      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000038ac      tbz   w0, 0, 0x100003848
|    `----> 0x1000038b0      ldr   x0, [x20, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|     ||:   0x1000038b4      bl    sym.imp.objc_opt_class
|     ||:   0x1000038b8      mov   x1, x0
|     ||:   0x1000038bc      mov   x0, x21
|     ||:   0x1000038c0      bl    sym.imp.objc_opt_isKindOfClass
|     ||:   0x1000038c4      mov   x24, x0
|     ||:   0x1000038c8      mov   x0, x21                             ; void *instance
|     ||:   0x1000038cc      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|     ||:   0x1000038d0      mov   x23, x0
|    ,====< 0x1000038d4      tbz   w24, 0, 0x1000039ac
|    |||:   0x1000038d8      movi  v0.2d, 0000000000000000
|    |||:   0x1000038dc      stp   q0, q0, [var_420h + 0x10]
|    |||:   0x1000038e0      stp   q0, q0, [var_430h]
|    |||:   0x1000038e4      add   x2, var_430h
|    |||:   0x1000038e8      add   x3, var_2f0h
|    |||:   0x1000038ec      mov   x0, x23
|    |||:   0x1000038f0      mov   w4, 0x10
|    |||:   0x1000038f4      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|    |||:   0x1000038f8      mov   x24, x0
|   ,=====< 0x1000038fc      cbz   x0, 0x1000039dc
|   ||||:   0x100003900      mov   x25, 0
|   ||||:   0x100003904      mov   w27, 0
|   ||||:   0x100003908      ldr   x8, [var_420h]                      ; [0x20:4]=-1 ; 32
|   ||||:   0x10000390c      ldr   x28, [x8]
|  .------> 0x100003910      mov   x20, 0
|  :||||:   0x100003914      mov   x26, x25
| .-------> 0x100003918      ldr   x8, [var_420h]                      ; [0x20:4]=-1 ; 32
| ::||||:   0x10000391c      ldr   x8, [x8]
| ::||||:   0x100003920      cmp   x8, x28
| ========< 0x100003924      b.eq  0x100003930
| ::||||:   0x100003928      mov   x0, x23                             ; void *instance
| ::||||:   0x10000392c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100003930      ldr   x8, [var_428h]                      ; [0x18:4]=-1 ; 24
| ::||||:   0x100003934      ldr   x0, [x8, x20, lsl 3]                ; void *instance
| ::||||:   0x100003938      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ::||||:   0x10000393c      mov   x25, x0
| ::||||:   0x100003940      mov   x0, x26                             ; void *instance
| ::||||:   0x100003944      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::||||:   0x100003948      mov   x1, x25                             ; int64_t arg3
| ::||||:   0x10000394c      mov   x2, x22
| ::||||:   0x100003950      bl    sym.func.100001fa0
| ::||||:   0x100003954      orr   w27, w27, w0
| ::||||:   0x100003958      add   x20, x20, 1
| ::||||:   0x10000395c      mov   x26, x25
| ::||||:   0x100003960      subs  x24, x24, 1
| `=======< 0x100003964      b.ne  0x100003918
|  :||||:   0x100003968      add   x2, var_430h
|  :||||:   0x10000396c      add   x3, var_2f0h
|  :||||:   0x100003970      mov   x0, x23
|  :||||:   0x100003974      mov   w4, 0x10
|  :||||:   0x100003978      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|  :||||:   0x10000397c      mov   x24, x0
|  `======< 0x100003980      cbnz  x0, 0x100003910
|   ||||:   0x100003984      mov   x0, x25                             ; void *instance
|   ||||:   0x100003988      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   ||||:   0x10000398c      mov   x26, 0
|  ,======< 0x100003990      tbz   w27, 0, 0x1000039e4
|  |||||:   0x100003994      mov   x25, x23
|  |||||:   0x100003998      mov   x23, x26
| ,=======< 0x10000399c      b     0x1000039c0
| ||||`---> 0x1000039a0      mov   x25, 0
| |||| |:   0x1000039a4      mov   x23, 0
| ||||,===< 0x1000039a8      b     0x1000039c4
| |||`----> 0x1000039ac      mov   x1, x23                             ; int64_t arg3
| ||| ||:   0x1000039b0      mov   x2, x22
| ||| ||:   0x1000039b4      bl    sym.func.100001fa0
| ||| ||:   0x1000039b8      mov   x25, 0
| |||,====< 0x1000039bc      cbz   w0, 0x1000039d0
| ||||||:   ; CODE XREF from sym.func.100002ea8 @ 0x10000399c
| `-------> 0x1000039c0      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
|  |||||:   ; CODE XREF from sym.func.100002ea8 @ 0x1000039a8
|  |||`---> 0x1000039c4      mov   w24, 1
|  ||| |:   0x1000039c8      mov   x26, x23
|  |||,===< 0x1000039cc      b     0x1000039f0
|  ||`----> 0x1000039d0      mov   w24, 0
|  || ||:   0x1000039d4      mov   x26, x23
|  ||,====< 0x1000039d8      b     0x1000039ec
|  |`-----> 0x1000039dc      mov   x26, 0
|  |,=====< 0x1000039e0      b     0x1000039e8
|  `------> 0x1000039e4      mov   w24, 0
|   ||||:   ; CODE XREF from sym.func.100002ea8 @ 0x1000039e0
|   `-----> 0x1000039e8      mov   x25, x23
|    |||:   ; CODE XREF from sym.func.100002ea8 @ 0x1000039d8
|    `----> 0x1000039ec      ldr   x28, [var_438h]                     ; [0x8:4]=-1 ; 8
|     ||:   ; CODE XREFS from sym.func.100002ea8 @ 0x100003854, 0x1000039cc
| ----`---> 0x1000039f0      mov   x0, x22                             ; void *instance
|      |:   0x1000039f4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|      |:   0x1000039f8      mov   x0, x26                             ; void *instance
|      |:   0x1000039fc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|      |:   0x100003a00      mov   x0, x25                             ; void *instance
|      |:   0x100003a04      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|      |:   0x100003a08      mov   x0, x21                             ; void *instance
|      |:   0x100003a0c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|      |`=< 0x100003a10      b     0x1000035d0
\      `--> 0x100003a14      bl    sym.imp.__stack_chk_fail            ; void __stack_chk_fail(void)
