[2K            ; CALL XREF from entry0 @ 0x100006294
/ sym.func.1000041cc(void *instance, int64_t arg2, int64_t arg3);
|           ; arg void *instance @ x0
|           ; arg int64_t arg2 @ x1
|           ; arg int64_t arg3 @ x2
|           ; var int64_t var_6d0h @ stack - 0x6d0
|           ; var int64_t var_6c8h @ stack - 0x6c8
|           ; var int64_t var_6b8h @ stack - 0x6b8
|           ; var int64_t var_6b0h @ stack - 0x6b0
|           ; var int64_t var_6a8h @ stack - 0x6a8
|           ; var int64_t var_6a0h @ stack - 0x6a0
|           ; var void *var_690h @ stack - 0x690
|           ; var void *var_688h @ stack - 0x688
|           ; var void *var_680h @ stack - 0x680
|           ; var int64_t var_678h @ stack - 0x678
|           ; var int64_t var_670h @ stack - 0x670
|           ; var int64_t var_668h @ stack - 0x668
|           ; var int64_t var_660h @ stack - 0x660
|           ; var int64_t var_630h @ stack - 0x630
|           ; var int64_t var_628h @ stack - 0x628
|           ; var int64_t var_620h @ stack - 0x620
|           ; var int64_t var_5f0h @ stack - 0x5f0
|           ; var int64_t var_5e8h @ stack - 0x5e8
|           ; var int64_t var_5e0h @ stack - 0x5e0
|           ; var int64_t var_5b0h @ stack - 0x5b0
|           ; var int64_t var_5a8h @ stack - 0x5a8
|           ; var int64_t var_5a0h @ stack - 0x5a0
|           ; var int64_t var_570h @ stack - 0x570
|           ; var int64_t var_568h @ stack - 0x568
|           ; var int64_t var_560h @ stack - 0x560
|           ; var int64_t var_530h @ stack - 0x530
|           ; var int64_t var_528h @ stack - 0x528
|           ; var int64_t var_520h @ stack - 0x520
|           ; var int64_t var_4f0h @ stack - 0x4f0
|           ; var int64_t var_4e8h @ stack - 0x4e8
|           ; var int64_t var_4e0h @ stack - 0x4e0
|           ; var int64_t var_4b0h @ stack - 0x4b0
|           ; var int64_t var_4a8h @ stack - 0x4a8
|           ; var int64_t var_4a0h @ stack - 0x4a0
|           ; var int64_t var_470h @ stack - 0x470
|           ; var int64_t var_3f0h @ stack - 0x3f0
|           ; var int64_t var_370h @ stack - 0x370
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
|           0x1000041cc      pacibsp
|           0x1000041d0      stp   x28, x27, [var_60h]!
|           0x1000041d4      stp   x26, x25, [var_50h]
|           0x1000041d8      stp   x24, x23, [var_40h]
|           0x1000041dc      stp   x22, x21, [var_30h]
|           0x1000041e0      stp   x20, x19, [var_20h]
|           0x1000041e4      stp   x29, x30, [var_10h]
|           0x1000041e8      add   x29, sp, 0x50
|           0x1000041ec      sub   sp, sp, 0x670
|           0x1000041f0      mov   x19, x2                             ; arg3
|           0x1000041f4      mov   x23, x1                             ; arg2
|           0x1000041f8      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x1000041fc      ldr   x8, [x8, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x100004200      ldr   x8, [x8]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x100004204      stur  x8, [var_60h]
|           0x100004208      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x10000420c      mov   x20, x0
|           0x100004210      mov   x0, x19                             ; void *instance
|           0x100004214      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100004218      mov   x19, x0
|           0x10000421c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100004220      ldr   x0, [x8, 0xc28]                     ; [0x10000cc28:4]=0x1c190 ; reloc.NSMutableArray
|           0x100004224      bl    stub.objc_msgSend_array             ;  stub.objc_msgSend_array(void)
|           0x100004228      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x10000422c      str   x0, [var_678h]
|           0x100004230      stp   x19, x20, [var_6c8h]
|           0x100004234      mov   x0, x20                             ; void *instance
|           0x100004238      mov   x1, x19                             ; int64_t arg2
|           0x10000423c      bl    sym.func.100000b5c
|           0x100004240      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100004244      mov   x24, x0
|           0x100004248      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x10000424c      ldr   x0, [x8, 0xc20]                     ; [0x10000cc20:4]=0x1c188 ; reloc.NSDictionary
|           0x100004250      bl    sym.imp.objc_opt_class
|           0x100004254      mov   x1, x0
|           0x100004258      mov   x0, x24
|           0x10000425c      bl    sym.imp.objc_opt_isKindOfClass
|       ,=< 0x100004260      tbz   w0, 0, 0x1000058f8
|       |   0x100004264      movi  v0.2d, 0000000000000000
|       |   0x100004268      stp   q0, q0, [var_4a0h + 0x10]
|       |   0x10000426c      stp   q0, q0, [var_4b0h]
|       |   0x100004270      str   x24, [sp]
|       |   0x100004274      mov   x0, x24                             ; void *instance
|       |   0x100004278      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|       |   0x10000427c      mov   x20, x0
|       |   0x100004280      add   x2, var_4b0h
|       |   0x100004284      sub   x3, var_10h + 0xf0
|       |   0x100004288      mov   w4, 0x10
|       |   0x10000428c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|       |   0x100004290      str   x0, [var_6a8h]
|      ,==< 0x100004294      cbz   x0, 0x1000058d0
|      ||   0x100004298      ldr   x8, [var_4a0h]                      ; [0x230:4]=-1 ; 560
|      ||   0x10000429c      ldr   x8, [x8]
|      ||   0x1000042a0      stp   x20, x8, [var_6b8h]
|     .---> 0x1000042a4      mov   x21, 0
|    .----> 0x1000042a8      ldr   x8, [var_4a0h]                      ; [0x230:4]=-1 ; 560
|    ::||   0x1000042ac      ldr   x8, [x8]
|    ::||   0x1000042b0      ldr   x9, [var_6b0h]                      ; [0x20:4]=-1 ; 32
|    ::||   0x1000042b4      cmp   x8, x9
|   ,=====< 0x1000042b8      b.eq  0x1000042c4
|   |::||   0x1000042bc      mov   x0, x20                             ; void *instance
|   |::||   0x1000042c0      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
|   `-----> 0x1000042c4      ldr   x8, [var_4a8h]                      ; [0x228:4]=-1 ; 552
|    ::||   0x1000042c8      ldr   x19, [x8, x21, lsl 3]
|    ::||   0x1000042cc      mov   x0, x20
|    ::||   0x1000042d0      mov   x2, x19
|    ::||   0x1000042d4      bl    stub.objc_msgSend_objectForKeyedSubscript: ;  stub.objc_msgSend_objectForKeyedSubscript:(void)
|    ::||   0x1000042d8      bl    sym.imp.objc_claimAutoreleasedReturnValue
|    ::||   0x1000042dc      mov   x22, x0
|    ::||   0x1000042e0      mov   x0, x19
|    ::||   0x1000042e4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|    ::||   0x1000042e8      add   x2, x2, 0x5a0                       ; 0x10000c5a0
|    ::||                                                              ; reloc.__CFConstantStringClassReference.10000c5a0
|    ::||   0x1000042ec      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
|   ,=====< 0x1000042f0      cbz   x0, 0x1000048a0
|   |::||   0x1000042f4      bl    sym.func.100001544
|   |::||   0x1000042f8      bl    sym.imp.objc_claimAutoreleasedReturnValue
|   |::||   0x1000042fc      mov   x24, x0
|   |::||   0x100004300      mov   x0, x19
|   |::||   0x100004304      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|   |::||   0x100004308      add   x2, x2, 0x5e0                       ; 0x10000c5e0
|   |::||                                                              ; reloc.__CFConstantStringClassReference.10000c5e0
|   |::||   0x10000430c      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
|  ,======< 0x100004310      cbz   x0, 0x100004e0c
|  ||::||   0x100004314      mov   x0, x19
|  ||::||   0x100004318      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::||   0x10000431c      add   x2, x2, 0x600                       ; 0x10000c600
|  ||::||                                                              ; reloc.__CFConstantStringClassReference.10000c600
|  ||::||   0x100004320      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ,=======< 0x100004324      cbz   x0, 0x1000053a8
| |||::||   0x100004328      mov   x0, x19
| |||::||   0x10000432c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004330      add   x2, x2, 0x620                       ; 0x10000c620
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c620
| |||::||   0x100004334      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100004338      cbnz  x0, 0x100005894
| |||::||   0x10000433c      stp   x22, x21, [var_6a0h]
| |||::||   0x100004340      mov   x0, x22                             ; void *instance
| |||::||   0x100004344      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||::||   0x100004348      stp   x24, x0, [var_688h]
| |||::||   0x10000434c      movi  v0.2d, 0000000000000000
| |||::||   0x100004350      stp   q0, q0, [var_630h]
| |||::||   0x100004354      stp   q0, q0, [var_620h + 0x10]
| |||::||   0x100004358      mov   x0, x24                             ; void *instance
| |||::||   0x10000435c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||::||   0x100004360      add   x2, var_630h
| |||::||   0x100004364      add   x3, var_3f0h
| |||::||   0x100004368      str   x0, [var_690h]
| |||::||   0x10000436c      mov   w4, 0x10
| |||::||   0x100004370      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x100004374      cbz   x0, 0x100005878
| |||::||   0x100004378      mov   x26, x0
| |||::||   0x10000437c      ldr   x8, [var_620h]                      ; [0xb0:4]=-1 ; 176
| |||::||   0x100004380      ldr   x20, [x8]
| --------> 0x100004384      mov   x27, 0
| --------> 0x100004388      ldr   x8, [var_620h]                      ; [0xb0:4]=-1 ; 176
| |||::||   0x10000438c      ldr   x8, [x8]
| |||::||   0x100004390      cmp   x8, x20
| ========< 0x100004394      b.eq  0x1000043a0
| |||::||   0x100004398      ldr   x0, [var_690h]                      ; [0x40:4]=-1 ; 64 ; void *instance
| |||::||   0x10000439c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x1000043a0      ldr   x8, [var_628h]                      ; [0xa8:4]=-1 ; 168
| |||::||   0x1000043a4      ldr   x25, [x8, x27, lsl 3]
| |||::||   0x1000043a8      movi  v0.2d, 0000000000000000
| |||::||   0x1000043ac      stp   q0, q0, [var_670h]
| |||::||   0x1000043b0      stp   q0, q0, [var_660h + 0x10]
| |||::||   0x1000043b4      ldr   x0, [var_680h]                      ; [0x50:4]=-1 ; 80 ; void *instance
| |||::||   0x1000043b8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||::||   0x1000043bc      mov   x24, x0
| |||::||   0x1000043c0      add   x2, var_670h
| |||::||   0x1000043c4      add   x3, var_470h
| |||::||   0x1000043c8      mov   w4, 0x10
| |||::||   0x1000043cc      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x1000043d0      cbz   x0, 0x10000486c
| |||::||   0x1000043d4      mov   x19, x0
| |||::||   0x1000043d8      ldr   x8, [var_660h]                      ; [0x70:4]=-1 ; 112
| |||::||   0x1000043dc      ldr   x28, [x8]
| --------> 0x1000043e0      mov   x22, 0
| --------> 0x1000043e4      ldr   x8, [var_660h]                      ; [0x70:4]=-1 ; 112
| |||::||   0x1000043e8      ldr   x8, [x8]
| |||::||   0x1000043ec      cmp   x8, x28
| ========< 0x1000043f0      b.eq  0x1000043fc
| |||::||   0x1000043f4      mov   x0, x24                             ; void *instance
| |||::||   0x1000043f8      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x1000043fc      ldr   x8, [var_668h]                      ; [0x68:4]=-1 ; 104
| |||::||   0x100004400      ldr   x21, [x8, x22, lsl 3]
| |||::||   0x100004404      mov   x0, x21                             ; void *instance
| |||::||   0x100004408      mov   x1, x25                             ; int64_t arg2
| |||::||   0x10000440c      mov   x2, x23                             ; int64_t arg3
| |||::||   0x100004410      bl    sym.func.10000218c
| ========< 0x100004414      cbnz  w0, 0x100004444
| |||::||   0x100004418      add   x22, x22, 1
| |||::||   0x10000441c      subs  x19, x19, 1
| ========< 0x100004420      b.ne  0x1000043e4
| |||::||   0x100004424      add   x2, var_670h
| |||::||   0x100004428      add   x3, var_470h
| |||::||   0x10000442c      mov   x0, x24
| |||::||   0x100004430      mov   w4, 0x10
| |||::||   0x100004434      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x100004438      mov   x19, x0
| ========< 0x10000443c      cbnz  x0, 0x1000043e0
| ========< 0x100004440      b     0x10000486c
| --------> 0x100004444      mov   x0, x21
| |||::||   0x100004448      bl    stub.objc_msgSend_mutableCopy       ;  stub.objc_msgSend_mutableCopy(void)
| |||::||   0x10000444c      mov   x19, x0
| |||::||   0x100004450      mov   x0, x25
| |||::||   0x100004454      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004458      add   x22, x22, 0x180                     ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x10000445c      mov   x2, x22
| |||::||   0x100004460      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004464      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004468      mov   x21, x0
| |||::||   0x10000446c      mov   x0, x19
| |||::||   0x100004470      mov   x2, x21
| |||::||   0x100004474      mov   x3, x22
| |||::||   0x100004478      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| |||::||   0x10000447c      mov   x0, x21                             ; void *instance
| |||::||   0x100004480      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004484      mov   x0, x19
| |||::||   0x100004488      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x10000448c      add   x22, x22, 0x360                     ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x100004490      mov   x2, x22
| |||::||   0x100004494      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004498      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000449c      mov   x21, x0
| |||::||   0x1000044a0      mov   x0, x25
| |||::||   0x1000044a4      mov   x2, x22
| |||::||   0x1000044a8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000044ac      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000044b0      mov   x28, x0
| |||::||   0x1000044b4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x1000044b8      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||::||   0x1000044bc      bl    sym.imp.objc_opt_class
| |||::||   0x1000044c0      mov   x1, x0
| |||::||   0x1000044c4      mov   x0, x21
| |||::||   0x1000044c8      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000044cc      tbnz  w0, 0, 0x1000044e4
| |||::||   0x1000044d0      mov   x0, x19
| |||::||   0x1000044d4      mov   x2, x28
| |||::||   0x1000044d8      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x1000044dc      add   x3, x3, 0x360                       ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x1000044e0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000044e4      mov   x0, x28                             ; void *instance
| |||::||   0x1000044e8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000044ec      mov   x0, x21                             ; void *instance
| |||::||   0x1000044f0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000044f4      mov   x0, x19
| |||::||   0x1000044f8      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x1000044fc      add   x2, x2, 0x180                       ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x100004500      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004504      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004508      mov   x21, x0
| |||::||   0x10000450c      mov   x0, x25
| |||::||   0x100004510      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004514      add   x22, x22, 0x4a0                     ; 0x10000c4a0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
| |||::||   0x100004518      mov   x2, x22
| |||::||   0x10000451c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004520      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004524      mov   x28, x0
| ========< 0x100004528      cbz   x21, 0x10000453c
| |||::||   0x10000452c      mov   x0, x19
| |||::||   0x100004530      mov   x2, x28
| |||::||   0x100004534      mov   x3, x22
| |||::||   0x100004538      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x10000453c      mov   x0, x28                             ; void *instance
| |||::||   0x100004540      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004544      mov   x0, x21                             ; void *instance
| |||::||   0x100004548      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000454c      mov   x0, x19
| |||::||   0x100004550      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004554      add   x22, x22, 0x3e0                     ; 0x10000c3e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| |||::||   0x100004558      mov   x2, x22
| |||::||   0x10000455c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004560      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004564      mov   x21, x0
| |||::||   0x100004568      mov   x0, x25
| |||::||   0x10000456c      mov   x2, x22
| |||::||   0x100004570      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004574      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004578      mov   x28, x0
| ========< 0x10000457c      cbz   x21, 0x100004590
| |||::||   0x100004580      mov   x0, x19
| |||::||   0x100004584      mov   x2, x28
| |||::||   0x100004588      mov   x3, x22
| |||::||   0x10000458c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004590      mov   x0, x28                             ; void *instance
| |||::||   0x100004594      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004598      mov   x0, x21                             ; void *instance
| |||::||   0x10000459c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000045a0      mov   x0, x19
| |||::||   0x1000045a4      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000045a8      add   x22, x22, 0x400                     ; 0x10000c400
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c400
| |||::||   0x1000045ac      mov   x2, x22
| |||::||   0x1000045b0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000045b4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000045b8      mov   x21, x0
| |||::||   0x1000045bc      mov   x0, x25
| |||::||   0x1000045c0      mov   x2, x22
| |||::||   0x1000045c4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000045c8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000045cc      mov   x28, x0
| ========< 0x1000045d0      cbz   x21, 0x1000045e4
| |||::||   0x1000045d4      mov   x0, x19
| |||::||   0x1000045d8      mov   x2, x28
| |||::||   0x1000045dc      mov   x3, x22
| |||::||   0x1000045e0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000045e4      mov   x0, x28                             ; void *instance
| |||::||   0x1000045e8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000045ec      mov   x0, x21                             ; void *instance
| |||::||   0x1000045f0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000045f4      mov   x0, x19
| |||::||   0x1000045f8      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000045fc      add   x22, x22, 0x420                     ; 0x10000c420
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c420
| |||::||   0x100004600      mov   x2, x22
| |||::||   0x100004604      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004608      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000460c      mov   x21, x0
| |||::||   0x100004610      mov   x0, x25
| |||::||   0x100004614      mov   x2, x22
| |||::||   0x100004618      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000461c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004620      mov   x28, x0
| ========< 0x100004624      cbz   x21, 0x100004638
| |||::||   0x100004628      mov   x0, x19
| |||::||   0x10000462c      mov   x2, x28
| |||::||   0x100004630      mov   x3, x22
| |||::||   0x100004634      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004638      mov   x0, x28                             ; void *instance
| |||::||   0x10000463c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004640      mov   x0, x21                             ; void *instance
| |||::||   0x100004644      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004648      mov   x0, x19
| |||::||   0x10000464c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004650      add   x22, x22, 0x460                     ; 0x10000c460
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c460
| |||::||   0x100004654      mov   x2, x22
| |||::||   0x100004658      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000465c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004660      mov   x21, x0
| |||::||   0x100004664      mov   x0, x25
| |||::||   0x100004668      mov   x2, x22
| |||::||   0x10000466c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004670      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004674      mov   x28, x0
| ========< 0x100004678      cbz   x21, 0x10000468c
| |||::||   0x10000467c      mov   x0, x19
| |||::||   0x100004680      mov   x2, x28
| |||::||   0x100004684      mov   x3, x22
| |||::||   0x100004688      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x10000468c      mov   x0, x28                             ; void *instance
| |||::||   0x100004690      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004694      mov   x0, x21                             ; void *instance
| |||::||   0x100004698      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000469c      mov   x0, x19
| |||::||   0x1000046a0      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000046a4      add   x22, x22, 0x4e0                     ; 0x10000c4e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
| |||::||   0x1000046a8      mov   x2, x22
| |||::||   0x1000046ac      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000046b0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000046b4      mov   x21, x0
| |||::||   0x1000046b8      mov   x0, x25
| |||::||   0x1000046bc      mov   x2, x22
| |||::||   0x1000046c0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000046c4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000046c8      mov   x28, x0
| ========< 0x1000046cc      cbz   x21, 0x1000046e0
| |||::||   0x1000046d0      mov   x0, x19
| |||::||   0x1000046d4      mov   x2, x28
| |||::||   0x1000046d8      mov   x3, x22
| |||::||   0x1000046dc      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000046e0      mov   x0, x28                             ; void *instance
| |||::||   0x1000046e4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000046e8      mov   x0, x21                             ; void *instance
| |||::||   0x1000046ec      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000046f0      mov   x0, x19
| |||::||   0x1000046f4      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000046f8      add   x22, x22, 0x1e0                     ; 0x10000c1e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c1e0
| |||::||   0x1000046fc      mov   x2, x22
| |||::||   0x100004700      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004704      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004708      mov   x21, x0
| |||::||   0x10000470c      mov   x0, x25
| |||::||   0x100004710      mov   x2, x22
| |||::||   0x100004714      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004718      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000471c      mov   x28, x0
| ========< 0x100004720      cbz   x21, 0x100004734
| |||::||   0x100004724      mov   x0, x19
| |||::||   0x100004728      mov   x2, x28
| |||::||   0x10000472c      mov   x3, x22
| |||::||   0x100004730      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004734      mov   x0, x28                             ; void *instance
| |||::||   0x100004738      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000473c      mov   x0, x21                             ; void *instance
| |||::||   0x100004740      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004744      mov   x0, x19
| |||::||   0x100004748      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x10000474c      add   x22, x22, 0x220                     ; 0x10000c220
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c220
| |||::||   0x100004750      mov   x2, x22
| |||::||   0x100004754      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004758      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000475c      mov   x21, x0
| |||::||   0x100004760      mov   x0, x25
| |||::||   0x100004764      mov   x2, x22
| |||::||   0x100004768      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000476c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004770      mov   x28, x0
| ========< 0x100004774      cbz   x21, 0x100004788
| |||::||   0x100004778      mov   x0, x19
| |||::||   0x10000477c      mov   x2, x28
| |||::||   0x100004780      mov   x3, x22
| |||::||   0x100004784      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004788      mov   x0, x28                             ; void *instance
| |||::||   0x10000478c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004790      mov   x0, x21                             ; void *instance
| |||::||   0x100004794      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004798      mov   x0, x19
| |||::||   0x10000479c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000047a0      add   x22, x22, 0x260                     ; 0x10000c260
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c260
| |||::||   0x1000047a4      mov   x2, x22
| |||::||   0x1000047a8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000047ac      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000047b0      mov   x21, x0
| |||::||   0x1000047b4      mov   x0, x25
| |||::||   0x1000047b8      mov   x2, x22
| |||::||   0x1000047bc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000047c0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000047c4      mov   x28, x0
| ========< 0x1000047c8      cbz   x21, 0x1000047dc
| |||::||   0x1000047cc      mov   x0, x19
| |||::||   0x1000047d0      mov   x2, x28
| |||::||   0x1000047d4      mov   x3, x22
| |||::||   0x1000047d8      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000047dc      mov   x0, x28                             ; void *instance
| |||::||   0x1000047e0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000047e4      mov   x0, x21                             ; void *instance
| |||::||   0x1000047e8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000047ec      mov   x0, x19
| |||::||   0x1000047f0      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000047f4      add   x22, x22, 0x300                     ; 0x10000c300
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c300
| |||::||   0x1000047f8      mov   x2, x22
| |||::||   0x1000047fc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004800      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004804      mov   x21, x0
| |||::||   0x100004808      mov   x0, x25
| |||::||   0x10000480c      mov   x2, x22
| |||::||   0x100004810      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004814      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004818      mov   x25, x0
| ========< 0x10000481c      cbz   x21, 0x100004830
| |||::||   0x100004820      mov   x0, x19
| |||::||   0x100004824      mov   x2, x25
| |||::||   0x100004828      mov   x3, x22
| |||::||   0x10000482c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004830      mov   x0, x25                             ; void *instance
| |||::||   0x100004834      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004838      mov   x0, x21                             ; void *instance
| |||::||   0x10000483c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004840      mov   x0, x19
| |||::||   0x100004844      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004848      add   x2, x2, 0x620                       ; 0x10000c620
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c620
| |||::||   0x10000484c      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004850      add   x3, x3, 0x5c0                       ; 0x10000c5c0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c5c0
| |||::||   0x100004854      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| |||::||   0x100004858      ldr   x0, [var_678h]                      ; [0x58:4]=-1 ; 88
| |||::||   0x10000485c      mov   x2, x19
| |||::||   0x100004860      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| |||::||   0x100004864      mov   x0, x19                             ; void *instance
| |||::||   0x100004868      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   ; CODE XREF from sym.func.1000041cc @ 0x100004440
| --------> 0x10000486c      mov   x0, x24                             ; void *instance
| |||::||   0x100004870      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004874      add   x27, x27, 1
| |||::||   0x100004878      cmp   x27, x26
| ========< 0x10000487c      b.ne  0x100004388
| |||::||   0x100004880      add   x2, var_630h
| |||::||   0x100004884      add   x3, var_3f0h
| |||::||   0x100004888      ldr   x0, [var_690h]                      ; [0x40:4]=-1 ; 64
| |||::||   0x10000488c      mov   w4, 0x10
| |||::||   0x100004890      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x100004894      mov   x26, x0
| ========< 0x100004898      cbnz  x0, 0x100004384
| ========< 0x10000489c      b     0x100005878
| ||`-----> 0x1000048a0      bl    sym.func.1000013c4
| || ::||   0x1000048a4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| || ::||   0x1000048a8      mov   x24, x0
| || ::||   0x1000048ac      mov   x0, x22                             ; void *instance
| || ::||   0x1000048b0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| || ::||   0x1000048b4      str   x0, [var_680h]
| || ::||   0x1000048b8      movi  v0.2d, 0000000000000000
| || ::||   0x1000048bc      stp   q0, q0, [var_4f0h]
| || ::||   0x1000048c0      stp   q0, q0, [var_4e0h + 0x10]
| || ::||   0x1000048c4      add   x2, var_4f0h
| || ::||   0x1000048c8      add   x3, var_170h
| || ::||   0x1000048cc      mov   x0, x24
| || ::||   0x1000048d0      mov   w4, 0x10
| || ::||   0x1000048d4      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ||,=====< 0x1000048d8      cbz   x0, 0x10000588c
| |||::||   0x1000048dc      mov   x26, x0
| |||::||   0x1000048e0      stp   x22, x21, [var_6a0h]
| |||::||   0x1000048e4      ldr   x8, [var_4e0h]                      ; [0x1f0:4]=-1 ; 496
| |||::||   0x1000048e8      ldr   x20, [x8]
| |||::||   0x1000048ec      str   x24, [var_688h]
| --------> 0x1000048f0      mov   x27, 0
| --------> 0x1000048f4      ldr   x8, [var_4e0h]                      ; [0x1f0:4]=-1 ; 496
| |||::||   0x1000048f8      ldr   x8, [x8]
| |||::||   0x1000048fc      cmp   x8, x20
| ========< 0x100004900      b.eq  0x10000490c
| |||::||   0x100004904      ldr   x0, [var_688h]                      ; [0x48:4]=-1 ; 72 ; void *instance
| |||::||   0x100004908      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x10000490c      ldr   x8, [var_4e8h]                      ; [0x1e8:4]=-1 ; 488
| |||::||   0x100004910      ldr   x25, [x8, x27, lsl 3]
| |||::||   0x100004914      movi  v0.2d, 0000000000000000
| |||::||   0x100004918      stp   q0, q0, [var_530h]
| |||::||   0x10000491c      stp   q0, q0, [var_520h + 0x10]
| |||::||   0x100004920      ldr   x0, [var_680h]                      ; [0x50:4]=-1 ; 80 ; void *instance
| |||::||   0x100004924      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||::||   0x100004928      mov   x24, x0
| |||::||   0x10000492c      add   x2, var_530h
| |||::||   0x100004930      add   x3, var_1f0h
| |||::||   0x100004934      mov   w4, 0x10
| |||::||   0x100004938      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x10000493c      cbz   x0, 0x100004dd4
| |||::||   0x100004940      mov   x19, x0
| |||::||   0x100004944      ldr   x8, [var_520h]                      ; [0x1b0:4]=-1 ; 432
| |||::||   0x100004948      ldr   x28, [x8]
| --------> 0x10000494c      mov   x22, 0
| --------> 0x100004950      ldr   x8, [var_520h]                      ; [0x1b0:4]=-1 ; 432
| |||::||   0x100004954      ldr   x8, [x8]
| |||::||   0x100004958      cmp   x8, x28
| ========< 0x10000495c      b.eq  0x100004968
| |||::||   0x100004960      mov   x0, x24                             ; void *instance
| |||::||   0x100004964      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100004968      ldr   x8, [var_528h]                      ; [0x1a8:4]=-1 ; 424
| |||::||   0x10000496c      ldr   x21, [x8, x22, lsl 3]
| |||::||   0x100004970      mov   x0, x21                             ; void *instance
| |||::||   0x100004974      mov   x1, x25                             ; int64_t arg2
| |||::||   0x100004978      bl    sym.func.100002ea8
| ========< 0x10000497c      cbnz  w0, 0x1000049ac
| |||::||   0x100004980      add   x22, x22, 1
| |||::||   0x100004984      subs  x19, x19, 1
| ========< 0x100004988      b.ne  0x100004950
| |||::||   0x10000498c      add   x2, var_530h
| |||::||   0x100004990      add   x3, var_1f0h
| |||::||   0x100004994      mov   x0, x24
| |||::||   0x100004998      mov   w4, 0x10
| |||::||   0x10000499c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x1000049a0      mov   x19, x0
| ========< 0x1000049a4      cbnz  x0, 0x10000494c
| ========< 0x1000049a8      b     0x100004dd4
| --------> 0x1000049ac      mov   x0, x21
| |||::||   0x1000049b0      bl    stub.objc_msgSend_mutableCopy       ;  stub.objc_msgSend_mutableCopy(void)
| |||::||   0x1000049b4      mov   x19, x0
| |||::||   0x1000049b8      mov   x0, x25
| |||::||   0x1000049bc      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000049c0      add   x22, x22, 0x180                     ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x1000049c4      mov   x2, x22
| |||::||   0x1000049c8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000049cc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000049d0      mov   x21, x0
| |||::||   0x1000049d4      mov   x0, x19
| |||::||   0x1000049d8      mov   x2, x21
| |||::||   0x1000049dc      mov   x3, x22
| |||::||   0x1000049e0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| |||::||   0x1000049e4      mov   x0, x21                             ; void *instance
| |||::||   0x1000049e8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000049ec      mov   x0, x19
| |||::||   0x1000049f0      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000049f4      add   x22, x22, 0x360                     ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x1000049f8      mov   x2, x22
| |||::||   0x1000049fc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004a00      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004a04      mov   x21, x0
| |||::||   0x100004a08      mov   x0, x25
| |||::||   0x100004a0c      mov   x2, x22
| |||::||   0x100004a10      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004a14      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004a18      mov   x28, x0
| |||::||   0x100004a1c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004a20      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||::||   0x100004a24      bl    sym.imp.objc_opt_class
| |||::||   0x100004a28      mov   x1, x0
| |||::||   0x100004a2c      mov   x0, x21
| |||::||   0x100004a30      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100004a34      tbnz  w0, 0, 0x100004a4c
| |||::||   0x100004a38      mov   x0, x19
| |||::||   0x100004a3c      mov   x2, x28
| |||::||   0x100004a40      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004a44      add   x3, x3, 0x360                       ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x100004a48      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004a4c      mov   x0, x28                             ; void *instance
| |||::||   0x100004a50      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004a54      mov   x0, x21                             ; void *instance
| |||::||   0x100004a58      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004a5c      mov   x0, x19
| |||::||   0x100004a60      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004a64      add   x2, x2, 0x180                       ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x100004a68      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004a6c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004a70      mov   x21, x0
| |||::||   0x100004a74      mov   x0, x25
| |||::||   0x100004a78      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004a7c      add   x22, x22, 0x4a0                     ; 0x10000c4a0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
| |||::||   0x100004a80      mov   x2, x22
| |||::||   0x100004a84      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004a88      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004a8c      mov   x28, x0
| ========< 0x100004a90      cbz   x21, 0x100004aa4
| |||::||   0x100004a94      mov   x0, x19
| |||::||   0x100004a98      mov   x2, x28
| |||::||   0x100004a9c      mov   x3, x22
| |||::||   0x100004aa0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004aa4      mov   x0, x28                             ; void *instance
| |||::||   0x100004aa8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004aac      mov   x0, x21                             ; void *instance
| |||::||   0x100004ab0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004ab4      mov   x0, x19
| |||::||   0x100004ab8      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004abc      add   x22, x22, 0x3e0                     ; 0x10000c3e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| |||::||   0x100004ac0      mov   x2, x22
| |||::||   0x100004ac4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004ac8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004acc      mov   x21, x0
| |||::||   0x100004ad0      mov   x0, x25
| |||::||   0x100004ad4      mov   x2, x22
| |||::||   0x100004ad8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004adc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004ae0      mov   x28, x0
| ========< 0x100004ae4      cbz   x21, 0x100004af8
| |||::||   0x100004ae8      mov   x0, x19
| |||::||   0x100004aec      mov   x2, x28
| |||::||   0x100004af0      mov   x3, x22
| |||::||   0x100004af4      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004af8      mov   x0, x28                             ; void *instance
| |||::||   0x100004afc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004b00      mov   x0, x21                             ; void *instance
| |||::||   0x100004b04      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004b08      mov   x0, x19
| |||::||   0x100004b0c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004b10      add   x22, x22, 0x400                     ; 0x10000c400
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c400
| |||::||   0x100004b14      mov   x2, x22
| |||::||   0x100004b18      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004b1c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004b20      mov   x21, x0
| |||::||   0x100004b24      mov   x0, x25
| |||::||   0x100004b28      mov   x2, x22
| |||::||   0x100004b2c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004b30      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004b34      mov   x28, x0
| ========< 0x100004b38      cbz   x21, 0x100004b4c
| |||::||   0x100004b3c      mov   x0, x19
| |||::||   0x100004b40      mov   x2, x28
| |||::||   0x100004b44      mov   x3, x22
| |||::||   0x100004b48      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004b4c      mov   x0, x28                             ; void *instance
| |||::||   0x100004b50      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004b54      mov   x0, x21                             ; void *instance
| |||::||   0x100004b58      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004b5c      mov   x0, x19
| |||::||   0x100004b60      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004b64      add   x22, x22, 0x420                     ; 0x10000c420
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c420
| |||::||   0x100004b68      mov   x2, x22
| |||::||   0x100004b6c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004b70      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004b74      mov   x21, x0
| |||::||   0x100004b78      mov   x0, x25
| |||::||   0x100004b7c      mov   x2, x22
| |||::||   0x100004b80      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004b84      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004b88      mov   x28, x0
| ========< 0x100004b8c      cbz   x21, 0x100004ba0
| |||::||   0x100004b90      mov   x0, x19
| |||::||   0x100004b94      mov   x2, x28
| |||::||   0x100004b98      mov   x3, x22
| |||::||   0x100004b9c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004ba0      mov   x0, x28                             ; void *instance
| |||::||   0x100004ba4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004ba8      mov   x0, x21                             ; void *instance
| |||::||   0x100004bac      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004bb0      mov   x0, x19
| |||::||   0x100004bb4      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004bb8      add   x22, x22, 0x460                     ; 0x10000c460
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c460
| |||::||   0x100004bbc      mov   x2, x22
| |||::||   0x100004bc0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004bc4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004bc8      mov   x21, x0
| |||::||   0x100004bcc      mov   x0, x25
| |||::||   0x100004bd0      mov   x2, x22
| |||::||   0x100004bd4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004bd8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004bdc      mov   x28, x0
| ========< 0x100004be0      cbz   x21, 0x100004bf4
| |||::||   0x100004be4      mov   x0, x19
| |||::||   0x100004be8      mov   x2, x28
| |||::||   0x100004bec      mov   x3, x22
| |||::||   0x100004bf0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004bf4      mov   x0, x28                             ; void *instance
| |||::||   0x100004bf8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004bfc      mov   x0, x21                             ; void *instance
| |||::||   0x100004c00      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004c04      mov   x0, x19
| |||::||   0x100004c08      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004c0c      add   x22, x22, 0x4e0                     ; 0x10000c4e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
| |||::||   0x100004c10      mov   x2, x22
| |||::||   0x100004c14      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004c18      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004c1c      mov   x21, x0
| |||::||   0x100004c20      mov   x0, x25
| |||::||   0x100004c24      mov   x2, x22
| |||::||   0x100004c28      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004c2c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004c30      mov   x28, x0
| ========< 0x100004c34      cbz   x21, 0x100004c48
| |||::||   0x100004c38      mov   x0, x19
| |||::||   0x100004c3c      mov   x2, x28
| |||::||   0x100004c40      mov   x3, x22
| |||::||   0x100004c44      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004c48      mov   x0, x28                             ; void *instance
| |||::||   0x100004c4c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004c50      mov   x0, x21                             ; void *instance
| |||::||   0x100004c54      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004c58      mov   x0, x19
| |||::||   0x100004c5c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004c60      add   x22, x22, 0x1e0                     ; 0x10000c1e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c1e0
| |||::||   0x100004c64      mov   x2, x22
| |||::||   0x100004c68      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004c6c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004c70      mov   x21, x0
| |||::||   0x100004c74      mov   x0, x25
| |||::||   0x100004c78      mov   x2, x22
| |||::||   0x100004c7c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004c80      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004c84      mov   x28, x0
| ========< 0x100004c88      cbz   x21, 0x100004c9c
| |||::||   0x100004c8c      mov   x0, x19
| |||::||   0x100004c90      mov   x2, x28
| |||::||   0x100004c94      mov   x3, x22
| |||::||   0x100004c98      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004c9c      mov   x0, x28                             ; void *instance
| |||::||   0x100004ca0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004ca4      mov   x0, x21                             ; void *instance
| |||::||   0x100004ca8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004cac      mov   x0, x19
| |||::||   0x100004cb0      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004cb4      add   x22, x22, 0x220                     ; 0x10000c220
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c220
| |||::||   0x100004cb8      mov   x2, x22
| |||::||   0x100004cbc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004cc0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004cc4      mov   x21, x0
| |||::||   0x100004cc8      mov   x0, x25
| |||::||   0x100004ccc      mov   x2, x22
| |||::||   0x100004cd0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004cd4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004cd8      mov   x28, x0
| ========< 0x100004cdc      cbz   x21, 0x100004cf0
| |||::||   0x100004ce0      mov   x0, x19
| |||::||   0x100004ce4      mov   x2, x28
| |||::||   0x100004ce8      mov   x3, x22
| |||::||   0x100004cec      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004cf0      mov   x0, x28                             ; void *instance
| |||::||   0x100004cf4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004cf8      mov   x0, x21                             ; void *instance
| |||::||   0x100004cfc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004d00      mov   x0, x19
| |||::||   0x100004d04      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004d08      add   x22, x22, 0x260                     ; 0x10000c260
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c260
| |||::||   0x100004d0c      mov   x2, x22
| |||::||   0x100004d10      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004d14      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004d18      mov   x21, x0
| |||::||   0x100004d1c      mov   x0, x25
| |||::||   0x100004d20      mov   x2, x22
| |||::||   0x100004d24      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004d28      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004d2c      mov   x28, x0
| ========< 0x100004d30      cbz   x21, 0x100004d44
| |||::||   0x100004d34      mov   x0, x19
| |||::||   0x100004d38      mov   x2, x28
| |||::||   0x100004d3c      mov   x3, x22
| |||::||   0x100004d40      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004d44      mov   x0, x28                             ; void *instance
| |||::||   0x100004d48      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004d4c      mov   x0, x21                             ; void *instance
| |||::||   0x100004d50      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004d54      mov   x0, x19
| |||::||   0x100004d58      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004d5c      add   x22, x22, 0x300                     ; 0x10000c300
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c300
| |||::||   0x100004d60      mov   x2, x22
| |||::||   0x100004d64      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004d68      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004d6c      mov   x21, x0
| |||::||   0x100004d70      mov   x0, x25
| |||::||   0x100004d74      mov   x2, x22
| |||::||   0x100004d78      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004d7c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004d80      mov   x25, x0
| ========< 0x100004d84      cbz   x21, 0x100004d98
| |||::||   0x100004d88      mov   x0, x19
| |||::||   0x100004d8c      mov   x2, x25
| |||::||   0x100004d90      mov   x3, x22
| |||::||   0x100004d94      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004d98      mov   x0, x25                             ; void *instance
| |||::||   0x100004d9c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004da0      mov   x0, x21                             ; void *instance
| |||::||   0x100004da4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004da8      mov   x0, x19
| |||::||   0x100004dac      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004db0      add   x2, x2, 0x5a0                       ; 0x10000c5a0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c5a0
| |||::||   0x100004db4      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004db8      add   x3, x3, 0x5c0                       ; 0x10000c5c0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c5c0
| |||::||   0x100004dbc      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| |||::||   0x100004dc0      ldr   x0, [var_678h]                      ; [0x58:4]=-1 ; 88
| |||::||   0x100004dc4      mov   x2, x19
| |||::||   0x100004dc8      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| |||::||   0x100004dcc      mov   x0, x19                             ; void *instance
| |||::||   0x100004dd0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   ; CODE XREF from sym.func.1000041cc @ 0x1000049a8
| --------> 0x100004dd4      mov   x0, x24                             ; void *instance
| |||::||   0x100004dd8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004ddc      add   x27, x27, 1
| |||::||   0x100004de0      cmp   x27, x26
| ========< 0x100004de4      b.ne  0x1000048f4
| |||::||   0x100004de8      add   x2, var_4f0h
| |||::||   0x100004dec      add   x3, var_170h
| |||::||   0x100004df0      ldr   x24, [var_688h]                     ; [0x48:4]=-1 ; 72
| |||::||   0x100004df4      mov   x0, x24
| |||::||   0x100004df8      mov   w4, 0x10
| |||::||   0x100004dfc      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x100004e00      mov   x26, x0
| ========< 0x100004e04      cbnz  x0, 0x1000048f0
| ========< 0x100004e08      b     0x100005884
| |`------> 0x100004e0c      stp   x22, x21, [var_6a0h]
| | |::||   0x100004e10      mov   x0, x22                             ; void *instance
| | |::||   0x100004e14      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| | |::||   0x100004e18      stp   x24, x0, [var_688h]
| | |::||   0x100004e1c      movi  v0.2d, 0000000000000000
| | |::||   0x100004e20      stp   q0, q0, [var_570h]
| | |::||   0x100004e24      stp   q0, q0, [var_560h + 0x10]
| | |::||   0x100004e28      mov   x0, x24                             ; void *instance
| | |::||   0x100004e2c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| | |::||   0x100004e30      add   x2, var_570h
| | |::||   0x100004e34      add   x3, var_270h
| | |::||   0x100004e38      str   x0, [var_690h]
| | |::||   0x100004e3c      mov   w4, 0x10
| | |::||   0x100004e40      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |,======< 0x100004e44      cbz   x0, 0x100005878
| |||::||   0x100004e48      mov   x26, x0
| |||::||   0x100004e4c      ldr   x8, [var_560h]                      ; [0x170:4]=-1 ; 368
| |||::||   0x100004e50      ldr   x20, [x8]
| --------> 0x100004e54      mov   x27, 0
| --------> 0x100004e58      ldr   x8, [var_560h]                      ; [0x170:4]=-1 ; 368
| |||::||   0x100004e5c      ldr   x8, [x8]
| |||::||   0x100004e60      cmp   x8, x20
| ========< 0x100004e64      b.eq  0x100004e70
| |||::||   0x100004e68      ldr   x0, [var_690h]                      ; [0x40:4]=-1 ; 64 ; void *instance
| |||::||   0x100004e6c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100004e70      ldr   x8, [var_568h]                      ; [0x168:4]=-1 ; 360
| |||::||   0x100004e74      ldr   x25, [x8, x27, lsl 3]
| |||::||   0x100004e78      movi  v0.2d, 0000000000000000
| |||::||   0x100004e7c      stp   q0, q0, [var_5b0h]
| |||::||   0x100004e80      stp   q0, q0, [var_5a0h + 0x10]
| |||::||   0x100004e84      ldr   x0, [var_680h]                      ; [0x50:4]=-1 ; 80 ; void *instance
| |||::||   0x100004e88      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||::||   0x100004e8c      mov   x24, x0
| |||::||   0x100004e90      add   x2, var_5b0h
| |||::||   0x100004e94      add   x3, var_2f0h
| |||::||   0x100004e98      mov   w4, 0x10
| |||::||   0x100004e9c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x100004ea0      cbz   x0, 0x100005374
| |||::||   0x100004ea4      mov   x19, x0
| |||::||   0x100004ea8      ldr   x8, [var_5a0h]                      ; [0x130:4]=-1 ; 304
| |||::||   0x100004eac      ldr   x28, [x8]
| --------> 0x100004eb0      mov   x22, 0
| --------> 0x100004eb4      ldr   x8, [var_5a0h]                      ; [0x130:4]=-1 ; 304
| |||::||   0x100004eb8      ldr   x8, [x8]
| |||::||   0x100004ebc      cmp   x8, x28
| ========< 0x100004ec0      b.eq  0x100004ecc
| |||::||   0x100004ec4      mov   x0, x24                             ; void *instance
| |||::||   0x100004ec8      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100004ecc      ldr   x8, [var_5a8h]                      ; [0x128:4]=-1 ; 296
| |||::||   0x100004ed0      ldr   x21, [x8, x22, lsl 3]
| |||::||   0x100004ed4      mov   x0, x21                             ; void *instance
| |||::||   0x100004ed8      mov   x1, x25                             ; int64_t arg2
| |||::||   0x100004edc      mov   x2, x23                             ; int64_t arg3
| |||::||   0x100004ee0      bl    sym.func.100003a18
| ========< 0x100004ee4      cbnz  w0, 0x100004f14
| |||::||   0x100004ee8      add   x22, x22, 1
| |||::||   0x100004eec      subs  x19, x19, 1
| ========< 0x100004ef0      b.ne  0x100004eb4
| |||::||   0x100004ef4      add   x2, var_5b0h
| |||::||   0x100004ef8      add   x3, var_2f0h
| |||::||   0x100004efc      mov   x0, x24
| |||::||   0x100004f00      mov   w4, 0x10
| |||::||   0x100004f04      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x100004f08      mov   x19, x0
| ========< 0x100004f0c      cbnz  x0, 0x100004eb0
| ========< 0x100004f10      b     0x100005374
| --------> 0x100004f14      mov   x0, x21
| |||::||   0x100004f18      bl    stub.objc_msgSend_mutableCopy       ;  stub.objc_msgSend_mutableCopy(void)
| |||::||   0x100004f1c      mov   x19, x0
| |||::||   0x100004f20      mov   x0, x25
| |||::||   0x100004f24      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004f28      add   x22, x22, 0x180                     ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x100004f2c      mov   x2, x22
| |||::||   0x100004f30      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004f34      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004f38      mov   x21, x0
| |||::||   0x100004f3c      mov   x0, x19
| |||::||   0x100004f40      mov   x2, x21
| |||::||   0x100004f44      mov   x3, x22
| |||::||   0x100004f48      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| |||::||   0x100004f4c      mov   x0, x21                             ; void *instance
| |||::||   0x100004f50      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004f54      mov   x0, x19
| |||::||   0x100004f58      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004f5c      add   x22, x22, 0x360                     ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x100004f60      mov   x2, x22
| |||::||   0x100004f64      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004f68      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004f6c      mov   x21, x0
| |||::||   0x100004f70      mov   x0, x25
| |||::||   0x100004f74      mov   x2, x22
| |||::||   0x100004f78      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004f7c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004f80      mov   x28, x0
| |||::||   0x100004f84      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004f88      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||::||   0x100004f8c      bl    sym.imp.objc_opt_class
| |||::||   0x100004f90      mov   x1, x0
| |||::||   0x100004f94      mov   x0, x21
| |||::||   0x100004f98      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100004f9c      tbnz  w0, 0, 0x100004fb4
| |||::||   0x100004fa0      mov   x0, x19
| |||::||   0x100004fa4      mov   x2, x28
| |||::||   0x100004fa8      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004fac      add   x3, x3, 0x360                       ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x100004fb0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100004fb4      mov   x0, x28                             ; void *instance
| |||::||   0x100004fb8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004fbc      mov   x0, x21                             ; void *instance
| |||::||   0x100004fc0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100004fc4      mov   x0, x19
| |||::||   0x100004fc8      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100004fcc      add   x2, x2, 0x180                       ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x100004fd0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004fd4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004fd8      mov   x21, x0
| |||::||   0x100004fdc      mov   x0, x25
| |||::||   0x100004fe0      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100004fe4      add   x22, x22, 0x4a0                     ; 0x10000c4a0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
| |||::||   0x100004fe8      mov   x2, x22
| |||::||   0x100004fec      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100004ff0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100004ff4      mov   x28, x0
| ========< 0x100004ff8      cbz   x21, 0x10000500c
| |||::||   0x100004ffc      mov   x0, x19
| |||::||   0x100005000      mov   x2, x28
| |||::||   0x100005004      mov   x3, x22
| |||::||   0x100005008      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x10000500c      mov   x0, x28                             ; void *instance
| |||::||   0x100005010      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005014      mov   x0, x21                             ; void *instance
| |||::||   0x100005018      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000501c      mov   x0, x19
| |||::||   0x100005020      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005024      add   x22, x22, 0x3e0                     ; 0x10000c3e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| |||::||   0x100005028      mov   x2, x22
| |||::||   0x10000502c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005030      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005034      mov   x21, x0
| |||::||   0x100005038      mov   x0, x25
| |||::||   0x10000503c      mov   x2, x22
| |||::||   0x100005040      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005044      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005048      mov   x28, x0
| ========< 0x10000504c      cbz   x21, 0x100005060
| |||::||   0x100005050      mov   x0, x19
| |||::||   0x100005054      mov   x2, x28
| |||::||   0x100005058      mov   x3, x22
| |||::||   0x10000505c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005060      mov   x0, x28                             ; void *instance
| |||::||   0x100005064      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005068      mov   x0, x21                             ; void *instance
| |||::||   0x10000506c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005070      mov   x0, x19
| |||::||   0x100005074      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005078      add   x22, x22, 0x400                     ; 0x10000c400
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c400
| |||::||   0x10000507c      mov   x2, x22
| |||::||   0x100005080      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005084      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005088      mov   x21, x0
| |||::||   0x10000508c      mov   x0, x25
| |||::||   0x100005090      mov   x2, x22
| |||::||   0x100005094      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005098      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000509c      mov   x28, x0
| ========< 0x1000050a0      cbz   x21, 0x1000050b4
| |||::||   0x1000050a4      mov   x0, x19
| |||::||   0x1000050a8      mov   x2, x28
| |||::||   0x1000050ac      mov   x3, x22
| |||::||   0x1000050b0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000050b4      mov   x0, x28                             ; void *instance
| |||::||   0x1000050b8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000050bc      mov   x0, x21                             ; void *instance
| |||::||   0x1000050c0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000050c4      mov   x0, x19
| |||::||   0x1000050c8      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000050cc      add   x22, x22, 0x420                     ; 0x10000c420
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c420
| |||::||   0x1000050d0      mov   x2, x22
| |||::||   0x1000050d4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000050d8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000050dc      mov   x21, x0
| |||::||   0x1000050e0      mov   x0, x25
| |||::||   0x1000050e4      mov   x2, x22
| |||::||   0x1000050e8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000050ec      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000050f0      mov   x28, x0
| ========< 0x1000050f4      cbz   x21, 0x100005108
| |||::||   0x1000050f8      mov   x0, x19
| |||::||   0x1000050fc      mov   x2, x28
| |||::||   0x100005100      mov   x3, x22
| |||::||   0x100005104      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005108      mov   x0, x28                             ; void *instance
| |||::||   0x10000510c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005110      mov   x0, x21                             ; void *instance
| |||::||   0x100005114      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005118      mov   x0, x19
| |||::||   0x10000511c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005120      add   x22, x22, 0x460                     ; 0x10000c460
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c460
| |||::||   0x100005124      mov   x2, x22
| |||::||   0x100005128      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000512c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005130      mov   x21, x0
| |||::||   0x100005134      mov   x0, x25
| |||::||   0x100005138      mov   x2, x22
| |||::||   0x10000513c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005140      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005144      mov   x28, x0
| ========< 0x100005148      cbz   x21, 0x10000515c
| |||::||   0x10000514c      mov   x0, x19
| |||::||   0x100005150      mov   x2, x28
| |||::||   0x100005154      mov   x3, x22
| |||::||   0x100005158      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x10000515c      mov   x0, x28                             ; void *instance
| |||::||   0x100005160      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005164      mov   x0, x21                             ; void *instance
| |||::||   0x100005168      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000516c      mov   x0, x19
| |||::||   0x100005170      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005174      add   x22, x22, 0x4e0                     ; 0x10000c4e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
| |||::||   0x100005178      mov   x2, x22
| |||::||   0x10000517c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005180      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005184      mov   x21, x0
| |||::||   0x100005188      mov   x0, x25
| |||::||   0x10000518c      mov   x2, x22
| |||::||   0x100005190      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005194      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005198      mov   x28, x0
| ========< 0x10000519c      cbz   x21, 0x1000051b0
| |||::||   0x1000051a0      mov   x0, x19
| |||::||   0x1000051a4      mov   x2, x28
| |||::||   0x1000051a8      mov   x3, x22
| |||::||   0x1000051ac      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000051b0      mov   x0, x28                             ; void *instance
| |||::||   0x1000051b4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000051b8      mov   x0, x21                             ; void *instance
| |||::||   0x1000051bc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000051c0      mov   x0, x19
| |||::||   0x1000051c4      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000051c8      add   x22, x22, 0x1e0                     ; 0x10000c1e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c1e0
| |||::||   0x1000051cc      mov   x2, x22
| |||::||   0x1000051d0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000051d4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000051d8      mov   x21, x0
| |||::||   0x1000051dc      mov   x0, x25
| |||::||   0x1000051e0      mov   x2, x22
| |||::||   0x1000051e4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000051e8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000051ec      mov   x28, x0
| ========< 0x1000051f0      cbz   x21, 0x100005204
| |||::||   0x1000051f4      mov   x0, x19
| |||::||   0x1000051f8      mov   x2, x28
| |||::||   0x1000051fc      mov   x3, x22
| |||::||   0x100005200      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005204      mov   x0, x28                             ; void *instance
| |||::||   0x100005208      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000520c      mov   x0, x21                             ; void *instance
| |||::||   0x100005210      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005214      mov   x0, x19
| |||::||   0x100005218      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x10000521c      add   x22, x22, 0x220                     ; 0x10000c220
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c220
| |||::||   0x100005220      mov   x2, x22
| |||::||   0x100005224      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005228      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000522c      mov   x21, x0
| |||::||   0x100005230      mov   x0, x25
| |||::||   0x100005234      mov   x2, x22
| |||::||   0x100005238      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000523c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005240      mov   x28, x0
| ========< 0x100005244      cbz   x21, 0x100005258
| |||::||   0x100005248      mov   x0, x19
| |||::||   0x10000524c      mov   x2, x28
| |||::||   0x100005250      mov   x3, x22
| |||::||   0x100005254      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005258      mov   x0, x28                             ; void *instance
| |||::||   0x10000525c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005260      mov   x0, x21                             ; void *instance
| |||::||   0x100005264      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005268      mov   x0, x19
| |||::||   0x10000526c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005270      add   x22, x22, 0x260                     ; 0x10000c260
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c260
| |||::||   0x100005274      mov   x2, x22
| |||::||   0x100005278      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000527c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005280      mov   x21, x0
| |||::||   0x100005284      mov   x0, x25
| |||::||   0x100005288      mov   x2, x22
| |||::||   0x10000528c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005290      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005294      mov   x28, x0
| ========< 0x100005298      cbz   x21, 0x1000052ac
| |||::||   0x10000529c      mov   x0, x19
| |||::||   0x1000052a0      mov   x2, x28
| |||::||   0x1000052a4      mov   x3, x22
| |||::||   0x1000052a8      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000052ac      mov   x0, x28                             ; void *instance
| |||::||   0x1000052b0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000052b4      mov   x0, x21                             ; void *instance
| |||::||   0x1000052b8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000052bc      mov   x0, x19
| |||::||   0x1000052c0      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000052c4      add   x22, x22, 0x300                     ; 0x10000c300
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c300
| |||::||   0x1000052c8      mov   x2, x22
| |||::||   0x1000052cc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000052d0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000052d4      mov   x21, x0
| |||::||   0x1000052d8      mov   x0, x25
| |||::||   0x1000052dc      mov   x2, x22
| |||::||   0x1000052e0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000052e4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000052e8      mov   x28, x0
| ========< 0x1000052ec      cbz   x21, 0x100005300
| |||::||   0x1000052f0      mov   x0, x19
| |||::||   0x1000052f4      mov   x2, x28
| |||::||   0x1000052f8      mov   x3, x22
| |||::||   0x1000052fc      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005300      mov   x0, x28                             ; void *instance
| |||::||   0x100005304      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005308      mov   x0, x21                             ; void *instance
| |||::||   0x10000530c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005310      mov   x0, x19
| |||::||   0x100005314      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100005318      add   x2, x2, 0x5e0                       ; 0x10000c5e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c5e0
| |||::||   0x10000531c      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100005320      add   x3, x3, 0x5c0                       ; 0x10000c5c0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c5c0
| |||::||   0x100005324      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| |||::||   0x100005328      mov   x0, x25
| |||::||   0x10000532c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005330      add   x22, x22, 0x2e0                     ; 0x10000c2e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c2e0
| |||::||   0x100005334      mov   x2, x22
| |||::||   0x100005338      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000533c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005340      mov   x21, x0
| ========< 0x100005344      cbz   x0, 0x100005358
| |||::||   0x100005348      mov   x0, x19
| |||::||   0x10000534c      mov   x2, x21
| |||::||   0x100005350      mov   x3, x22
| |||::||   0x100005354      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| --------> 0x100005358      ldr   x0, [var_678h]                      ; [0x58:4]=-1 ; 88
| |||::||   0x10000535c      mov   x2, x19
| |||::||   0x100005360      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| |||::||   0x100005364      mov   x0, x21                             ; void *instance
| |||::||   0x100005368      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000536c      mov   x0, x19                             ; void *instance
| |||::||   0x100005370      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   ; CODE XREF from sym.func.1000041cc @ 0x100004f10
| --------> 0x100005374      mov   x0, x24                             ; void *instance
| |||::||   0x100005378      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000537c      add   x27, x27, 1
| |||::||   0x100005380      cmp   x27, x26
| ========< 0x100005384      b.ne  0x100004e58
| |||::||   0x100005388      add   x2, var_570h
| |||::||   0x10000538c      add   x3, var_270h
| |||::||   0x100005390      ldr   x0, [var_690h]                      ; [0x40:4]=-1 ; 64
| |||::||   0x100005394      mov   w4, 0x10
| |||::||   0x100005398      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x10000539c      mov   x26, x0
| ========< 0x1000053a0      cbnz  x0, 0x100004e54
| ========< 0x1000053a4      b     0x100005878
| `-------> 0x1000053a8      stp   x22, x21, [var_6a0h]
|  ||::||   0x1000053ac      mov   x0, x22                             ; void *instance
|  ||::||   0x1000053b0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  ||::||   0x1000053b4      mov   x22, x0
|  ||::||   0x1000053b8      movi  v0.2d, 0000000000000000
|  ||::||   0x1000053bc      stp   q0, q0, [var_5f0h]
|  ||::||   0x1000053c0      stp   q0, q0, [var_5e0h + 0x10]
|  ||::||   0x1000053c4      str   x24, [var_688h]
|  ||::||   0x1000053c8      mov   x0, x24                             ; void *instance
|  ||::||   0x1000053cc      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  ||::||   0x1000053d0      add   x2, var_5f0h
|  ||::||   0x1000053d4      add   x3, var_370h
|  ||::||   0x1000053d8      str   x0, [var_680h]
|  ||::||   0x1000053dc      mov   w4, 0x10
|  ||::||   0x1000053e0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ,=======< 0x1000053e4      cbz   x0, 0x100005878
| |||::||   0x1000053e8      mov   x25, x0
| |||::||   0x1000053ec      ldr   x8, [var_5e0h]                      ; [0xf0:4]=-1 ; 240
| |||::||   0x1000053f0      ldr   x20, [x8]
| --------> 0x1000053f4      mov   x27, 0
| --------> 0x1000053f8      ldr   x8, [var_5e0h]                      ; [0xf0:4]=-1 ; 240
| |||::||   0x1000053fc      ldr   x8, [x8]
| |||::||   0x100005400      cmp   x8, x20
| ========< 0x100005404      b.eq  0x100005410
| |||::||   0x100005408      ldr   x0, [var_680h]                      ; [0x50:4]=-1 ; 80 ; void *instance
| |||::||   0x10000540c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100005410      ldr   x8, [var_5e8h]                      ; [0xe8:4]=-1 ; 232
| |||::||   0x100005414      ldr   x26, [x8, x27, lsl 3]
| |||::||   0x100005418      mov   x0, x22                             ; void *instance
| |||::||   0x10000541c      mov   x1, x26                             ; int64_t arg2
| |||::||   0x100005420      bl    sym.func.100001ad8
| ========< 0x100005424      cbz   w0, 0x100005850
| |||::||   0x100005428      mov   x0, x22
| |||::||   0x10000542c      bl    stub.objc_msgSend_mutableCopy       ;  stub.objc_msgSend_mutableCopy(void)
| |||::||   0x100005430      mov   x19, x0
| |||::||   0x100005434      mov   x0, x26
| |||::||   0x100005438      adrp  x28, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x10000543c      add   x28, x28, 0x180                     ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x100005440      mov   x2, x28
| |||::||   0x100005444      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005448      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000544c      mov   x21, x0
| |||::||   0x100005450      mov   x0, x19
| |||::||   0x100005454      mov   x2, x21
| |||::||   0x100005458      mov   x3, x28
| |||::||   0x10000545c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| |||::||   0x100005460      mov   x0, x21                             ; void *instance
| |||::||   0x100005464      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005468      mov   x0, x19
| |||::||   0x10000546c      adrp  x28, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005470      add   x28, x28, 0x360                     ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x100005474      mov   x2, x28
| |||::||   0x100005478      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000547c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005480      mov   x21, x0
| |||::||   0x100005484      mov   x0, x26
| |||::||   0x100005488      mov   x2, x28
| |||::||   0x10000548c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005490      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005494      mov   x28, x0
| |||::||   0x100005498      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x10000549c      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||::||   0x1000054a0      bl    sym.imp.objc_opt_class
| |||::||   0x1000054a4      mov   x1, x0
| |||::||   0x1000054a8      mov   x0, x21
| |||::||   0x1000054ac      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000054b0      tbnz  w0, 0, 0x1000054c8
| |||::||   0x1000054b4      mov   x0, x19
| |||::||   0x1000054b8      mov   x2, x28
| |||::||   0x1000054bc      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x1000054c0      add   x3, x3, 0x360                       ; 0x10000c360
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| |||::||   0x1000054c4      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000054c8      mov   x0, x28                             ; void *instance
| |||::||   0x1000054cc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000054d0      mov   x0, x21                             ; void *instance
| |||::||   0x1000054d4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000054d8      mov   x0, x19
| |||::||   0x1000054dc      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x1000054e0      add   x2, x2, 0x180                       ; 0x10000c180
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| |||::||   0x1000054e4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000054e8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000054ec      mov   x21, x0
| |||::||   0x1000054f0      mov   x0, x26
| |||::||   0x1000054f4      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000054f8      add   x24, x24, 0x4a0                     ; 0x10000c4a0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
| |||::||   0x1000054fc      mov   x2, x24
| |||::||   0x100005500      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005504      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005508      mov   x28, x0
| ========< 0x10000550c      cbz   x21, 0x100005520
| |||::||   0x100005510      mov   x0, x19
| |||::||   0x100005514      mov   x2, x28
| |||::||   0x100005518      mov   x3, x24
| |||::||   0x10000551c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005520      mov   x0, x28                             ; void *instance
| |||::||   0x100005524      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005528      mov   x0, x21                             ; void *instance
| |||::||   0x10000552c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005530      mov   x0, x19
| |||::||   0x100005534      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005538      add   x24, x24, 0x3e0                     ; 0x10000c3e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| |||::||   0x10000553c      mov   x2, x24
| |||::||   0x100005540      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005544      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005548      mov   x21, x0
| |||::||   0x10000554c      mov   x0, x26
| |||::||   0x100005550      mov   x2, x24
| |||::||   0x100005554      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005558      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000555c      mov   x28, x0
| ========< 0x100005560      cbz   x21, 0x100005574
| |||::||   0x100005564      mov   x0, x19
| |||::||   0x100005568      mov   x2, x28
| |||::||   0x10000556c      mov   x3, x24
| |||::||   0x100005570      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005574      mov   x0, x28                             ; void *instance
| |||::||   0x100005578      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000557c      mov   x0, x21                             ; void *instance
| |||::||   0x100005580      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005584      mov   x0, x19
| |||::||   0x100005588      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x10000558c      add   x24, x24, 0x400                     ; 0x10000c400
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c400
| |||::||   0x100005590      mov   x2, x24
| |||::||   0x100005594      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005598      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x10000559c      mov   x21, x0
| |||::||   0x1000055a0      mov   x0, x26
| |||::||   0x1000055a4      mov   x2, x24
| |||::||   0x1000055a8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000055ac      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000055b0      mov   x28, x0
| ========< 0x1000055b4      cbz   x21, 0x1000055c8
| |||::||   0x1000055b8      mov   x0, x19
| |||::||   0x1000055bc      mov   x2, x28
| |||::||   0x1000055c0      mov   x3, x24
| |||::||   0x1000055c4      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000055c8      mov   x0, x28                             ; void *instance
| |||::||   0x1000055cc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000055d0      mov   x0, x21                             ; void *instance
| |||::||   0x1000055d4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000055d8      mov   x0, x19
| |||::||   0x1000055dc      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000055e0      add   x24, x24, 0x420                     ; 0x10000c420
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c420
| |||::||   0x1000055e4      mov   x2, x24
| |||::||   0x1000055e8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000055ec      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000055f0      mov   x21, x0
| |||::||   0x1000055f4      mov   x0, x26
| |||::||   0x1000055f8      mov   x2, x24
| |||::||   0x1000055fc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005600      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005604      mov   x28, x0
| ========< 0x100005608      cbz   x21, 0x10000561c
| |||::||   0x10000560c      mov   x0, x19
| |||::||   0x100005610      mov   x2, x28
| |||::||   0x100005614      mov   x3, x24
| |||::||   0x100005618      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x10000561c      mov   x0, x28                             ; void *instance
| |||::||   0x100005620      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005624      mov   x0, x21                             ; void *instance
| |||::||   0x100005628      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000562c      mov   x0, x19
| |||::||   0x100005630      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005634      add   x24, x24, 0x460                     ; 0x10000c460
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c460
| |||::||   0x100005638      mov   x2, x24
| |||::||   0x10000563c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005640      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005644      mov   x21, x0
| |||::||   0x100005648      mov   x0, x26
| |||::||   0x10000564c      mov   x2, x24
| |||::||   0x100005650      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005654      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005658      mov   x28, x0
| ========< 0x10000565c      cbz   x21, 0x100005670
| |||::||   0x100005660      mov   x0, x19
| |||::||   0x100005664      mov   x2, x28
| |||::||   0x100005668      mov   x3, x24
| |||::||   0x10000566c      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005670      mov   x0, x28                             ; void *instance
| |||::||   0x100005674      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005678      mov   x0, x21                             ; void *instance
| |||::||   0x10000567c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005680      mov   x0, x19
| |||::||   0x100005684      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005688      add   x24, x24, 0x4e0                     ; 0x10000c4e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
| |||::||   0x10000568c      mov   x2, x24
| |||::||   0x100005690      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005694      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005698      mov   x21, x0
| |||::||   0x10000569c      mov   x0, x26
| |||::||   0x1000056a0      mov   x2, x24
| |||::||   0x1000056a4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000056a8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000056ac      mov   x28, x0
| ========< 0x1000056b0      cbz   x21, 0x1000056c4
| |||::||   0x1000056b4      mov   x0, x19
| |||::||   0x1000056b8      mov   x2, x28
| |||::||   0x1000056bc      mov   x3, x24
| |||::||   0x1000056c0      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000056c4      mov   x0, x28                             ; void *instance
| |||::||   0x1000056c8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000056cc      mov   x0, x21                             ; void *instance
| |||::||   0x1000056d0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000056d4      mov   x0, x19
| |||::||   0x1000056d8      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000056dc      add   x24, x24, 0x1e0                     ; 0x10000c1e0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c1e0
| |||::||   0x1000056e0      mov   x2, x24
| |||::||   0x1000056e4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000056e8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000056ec      mov   x21, x0
| |||::||   0x1000056f0      mov   x0, x26
| |||::||   0x1000056f4      mov   x2, x24
| |||::||   0x1000056f8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000056fc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005700      mov   x28, x0
| ========< 0x100005704      cbz   x21, 0x100005718
| |||::||   0x100005708      mov   x0, x19
| |||::||   0x10000570c      mov   x2, x28
| |||::||   0x100005710      mov   x3, x24
| |||::||   0x100005714      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005718      mov   x0, x28                             ; void *instance
| |||::||   0x10000571c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005720      mov   x0, x21                             ; void *instance
| |||::||   0x100005724      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005728      mov   x0, x19
| |||::||   0x10000572c      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005730      add   x24, x24, 0x220                     ; 0x10000c220
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c220
| |||::||   0x100005734      mov   x2, x24
| |||::||   0x100005738      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x10000573c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005740      mov   x21, x0
| |||::||   0x100005744      mov   x0, x26
| |||::||   0x100005748      mov   x2, x24
| |||::||   0x10000574c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005750      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005754      mov   x28, x0
| ========< 0x100005758      cbz   x21, 0x10000576c
| |||::||   0x10000575c      mov   x0, x19
| |||::||   0x100005760      mov   x2, x28
| |||::||   0x100005764      mov   x3, x24
| |||::||   0x100005768      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x10000576c      mov   x0, x28                             ; void *instance
| |||::||   0x100005770      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005774      mov   x0, x21                             ; void *instance
| |||::||   0x100005778      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000577c      mov   x0, x19
| |||::||   0x100005780      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x100005784      add   x24, x24, 0x260                     ; 0x10000c260
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c260
| |||::||   0x100005788      mov   x2, x24
| |||::||   0x10000578c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x100005790      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x100005794      mov   x21, x0
| |||::||   0x100005798      mov   x0, x26
| |||::||   0x10000579c      mov   x2, x24
| |||::||   0x1000057a0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000057a4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000057a8      mov   x28, x0
| ========< 0x1000057ac      cbz   x21, 0x1000057c0
| |||::||   0x1000057b0      mov   x0, x19
| |||::||   0x1000057b4      mov   x2, x28
| |||::||   0x1000057b8      mov   x3, x24
| |||::||   0x1000057bc      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x1000057c0      mov   x0, x28                             ; void *instance
| |||::||   0x1000057c4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000057c8      mov   x0, x21                             ; void *instance
| |||::||   0x1000057cc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x1000057d0      mov   x0, x19
| |||::||   0x1000057d4      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::||   0x1000057d8      add   x24, x24, 0x300                     ; 0x10000c300
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c300
| |||::||   0x1000057dc      mov   x2, x24
| |||::||   0x1000057e0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000057e4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000057e8      mov   x21, x0
| |||::||   0x1000057ec      mov   x0, x26
| |||::||   0x1000057f0      mov   x2, x24
| |||::||   0x1000057f4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||::||   0x1000057f8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||::||   0x1000057fc      mov   x26, x0
| ========< 0x100005800      cbz   x21, 0x100005814
| |||::||   0x100005804      mov   x0, x19
| |||::||   0x100005808      mov   x2, x26
| |||::||   0x10000580c      mov   x3, x24
| |||::||   0x100005810      bl    stub.objc_msgSend_setObject:forKeyedSubscript: ;  stub.objc_msgSend_setObject:forKeyedSubscript:(void)
| --------> 0x100005814      mov   x0, x26                             ; void *instance
| |||::||   0x100005818      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x10000581c      mov   x0, x21                             ; void *instance
| |||::||   0x100005820      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||::||   0x100005824      mov   x0, x19
| |||::||   0x100005828      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x10000582c      add   x2, x2, 0x600                       ; 0x10000c600
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c600
| |||::||   0x100005830      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::||   0x100005834      add   x3, x3, 0x5c0                       ; 0x10000c5c0
| |||::||                                                              ; reloc.__CFConstantStringClassReference.10000c5c0
| |||::||   0x100005838      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| |||::||   0x10000583c      ldr   x0, [var_678h]                      ; [0x58:4]=-1 ; 88
| |||::||   0x100005840      mov   x2, x19
| |||::||   0x100005844      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| |||::||   0x100005848      mov   x0, x19                             ; void *instance
| |||::||   0x10000584c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| --------> 0x100005850      add   x27, x27, 1
| |||::||   0x100005854      subs  x25, x25, 1
| ========< 0x100005858      b.ne  0x1000053f8
| |||::||   0x10000585c      add   x2, var_5f0h
| |||::||   0x100005860      add   x3, var_370h
| |||::||   0x100005864      ldr   x0, [var_680h]                      ; [0x50:4]=-1 ; 80
| |||::||   0x100005868      mov   w4, 0x10
| |||::||   0x10000586c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::||   0x100005870      mov   x25, x0
| ========< 0x100005874      cbnz  x0, 0x1000053f4
| |||::||   ; CODE XREFS from sym.func.1000041cc @ 0x10000489c, 0x1000053a4
| ``------> 0x100005878      ldr   x24, [var_688h]                     ; [0x48:4]=-1 ; 72
|   |::||   0x10000587c      mov   x0, x24                             ; void *instance
|   |::||   0x100005880      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |::||   ; CODE XREF from sym.func.1000041cc @ 0x100004e08
| --------> 0x100005884      ldr   x20, [var_6b8h]                     ; [0x18:4]=-1 ; 24
|   |::||   0x100005888      ldp   x22, x21, [var_6a0h]
|   `-----> 0x10000588c      mov   x0, x22                             ; void *instance
|    ::||   0x100005890      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| --------> 0x100005894      mov   x0, x24                             ; void *instance
|    ::||   0x100005898      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::||   0x10000589c      mov   x0, x22                             ; void *instance
|    ::||   0x1000058a0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::||   0x1000058a4      add   x21, x21, 1
|    ::||   0x1000058a8      ldr   x8, [var_6a8h]                      ; [0x28:4]=-1 ; 40
|    ::||   0x1000058ac      cmp   x21, x8
|    `====< 0x1000058b0      b.ne  0x1000042a8
|     :||   0x1000058b4      add   x2, var_4b0h
|     :||   0x1000058b8      sub   x3, var_10h + 0xf0
|     :||   0x1000058bc      mov   x0, x20
|     :||   0x1000058c0      mov   w4, 0x10
|     :||   0x1000058c4      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|     :||   0x1000058c8      str   x0, [var_6a8h]
|     `===< 0x1000058cc      cbnz  x0, 0x1000042a4
|      `--> 0x1000058d0      mov   x0, x20                             ; void *instance
|       |   0x1000058d4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|       |   0x1000058d8      ldr   x22, [var_678h]                     ; [0x58:4]=-1 ; 88
|       |   0x1000058dc      mov   x0, x22
|       |   0x1000058e0      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
|      ,==< 0x1000058e4      cbz   x0, 0x100005918
|      ||   0x1000058e8      mov   x0, x22                             ; void *instance
|      ||   0x1000058ec      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|      ||   0x1000058f0      mov   x19, x0
|     ,===< 0x1000058f4      b     0x10000591c
|     ||`-> 0x1000058f8      adrp  x0, section.7.__DATA_CONST.__const  ; 0x10000c000
|     ||    0x1000058fc      add   x0, x0, 0x580                       ; 0x10000c580
|     ||                                                               ; reloc.__CFConstantStringClassReference.10000c580
|     ||    0x100005900      bl    sym.imp.NSLog
|     ||    0x100005904      mov   x19, 0
|     ||    0x100005908      ldp   x21, x20, [var_6c8h]
|     ||    0x10000590c      ldr   x22, [var_678h]                     ; [0x58:4]=-1 ; 88
|     ||    0x100005910      mov   x0, x24
|     ||,=< 0x100005914      b     0x100005924
|     |`--> 0x100005918      mov   x19, 0
|     | |   ; CODE XREF from sym.func.1000041cc @ 0x1000058f4
|     `---> 0x10000591c      ldp   x21, x20, [var_6c8h]
|       |   0x100005920      ldr   x0, [sp]
|       |   ; CODE XREF from sym.func.1000041cc @ 0x100005914
|       `-> 0x100005924      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005928      mov   x0, x22                             ; void *instance
|           0x10000592c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005930      mov   x0, x21                             ; void *instance
|           0x100005934      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005938      mov   x0, x20                             ; void *instance
|           0x10000593c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005940      ldur  x8, [var_60h]
|           0x100005944      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100005948      ldr   x9, [x9, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x10000594c      ldr   x9, [x9]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x100005950      cmp   x9, x8
|       ,=< 0x100005954      b.ne  0x10000598c
|       |   0x100005958      mov   x0, x19
|       |   0x10000595c      add   sp, sp, 0x670
|       |   0x100005960      ldp   x29, x30, [var_10h]
|       |   0x100005964      ldp   x20, x19, [var_20h]
|       |   0x100005968      ldp   x22, x21, [var_30h]
|       |   0x10000596c      ldp   x24, x23, [var_40h]
|       |   0x100005970      ldp   x26, x25, [var_50h]
|       |   0x100005974      ldp   x28, x27, [sp], 0x60
|       |   0x100005978      autibsp
|       |   0x10000597c      eor   x16, x30, x30, lsl 1
|      ,==< 0x100005980      tbz   x16, 0x3e, 0x100005988
|      ||   0x100005984      brk   0xc471
|     ,`--> 0x100005988      b     sym.imp.objc_autoreleaseReturnValue
\     | `-> 0x10000598c      bl    sym.imp.__stack_chk_fail            ; void __stack_chk_fail(void)
