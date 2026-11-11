[2K            ;-- main:
            ;-- func.100005990:
            ;-- pc:
/ entry0(void *arg2, void *arg1);
|           ; arg void *arg1 @ x0
|           ; arg void *arg2 @ x1
|           ; var int64_t var_6f0h @ stack - 0x6f0
|           ; var int64_t var_6e8h @ stack - 0x6e8
|           ; var int64_t var_6d8h @ stack - 0x6d8
|           ; var void *var_6d0h @ stack - 0x6d0
|           ; var void *var_6c8h @ stack - 0x6c8
|           ; var int64_t var_6c0h @ stack - 0x6c0
|           ; var int64_t var_6b8h @ stack - 0x6b8
|           ; var int64_t var_6b0h @ stack - 0x6b0
|           ; var void *var_6a8h @ stack - 0x6a8
|           ; var int64_t var_6a0h @ stack - 0x6a0
|           ; var int64_t var_694h @ stack - 0x694
|           ; var void *var_690h @ stack - 0x690
|           ; var int64_t var_688h @ stack - 0x688
|           ; var int64_t var_67ch @ stack - 0x67c
|           ; var int64_t var_678h @ stack - 0x678
|           ; var void *var_670h @ stack - 0x670
|           ; var int64_t var_668h @ stack - 0x668
|           ; var int64_t var_660h @ stack - 0x660
|           ; var int64_t var_658h @ stack - 0x658
|           ; var void *var_650h @ stack - 0x650
|           ; var void *var_648h @ stack - 0x648
|           ; var void *var_640h @ stack - 0x640
|           ; var void *var_638h @ stack - 0x638
|           ; var void *var_630h @ stack - 0x630
|           ; var void *var_628h @ stack - 0x628
|           ; var void *var_620h @ stack - 0x620
|           ; var void *var_618h @ stack - 0x618
|           ; var void *var_610h @ stack - 0x610
|           ; var void *var_608h @ stack - 0x608
|           ; var void *var_600h @ stack - 0x600
|           ; var void *var_5f8h @ stack - 0x5f8
|           ; var int64_t var_5f0h @ stack - 0x5f0
|           ; var int64_t var_5e8h @ stack - 0x5e8
|           ; var void *instance @ stack - 0x5e0
|           ; var void *var_5d8h @ stack - 0x5d8
|           ; var int64_t var_5d0h @ stack - 0x5d0
|           ; var int64_t var_5c8h @ stack - 0x5c8
|           ; var int64_t var_5c0h @ stack - 0x5c0
|           ; var int64_t var_590h @ stack - 0x590
|           ; var int64_t var_588h @ stack - 0x588
|           ; var int64_t var_580h @ stack - 0x580
|           ; var int64_t var_550h @ stack - 0x550
|           ; var int64_t var_548h @ stack - 0x548
|           ; var int64_t var_540h @ stack - 0x540
|           ; var int64_t var_510h @ stack - 0x510
|           ; var int64_t var_508h @ stack - 0x508
|           ; var int64_t var_500h @ stack - 0x500
|           ; var int64_t var_4d0h @ stack - 0x4d0
|           ; var int64_t var_4c8h @ stack - 0x4c8
|           ; var int64_t var_4c0h @ stack - 0x4c0
|           ; var int64_t var_490h @ stack - 0x490
|           ; var int64_t var_488h @ stack - 0x488
|           ; var int64_t var_480h @ stack - 0x480
|           ; var int64_t var_450h @ stack - 0x450
|           ; var int64_t var_449h @ stack - 0x449
|           ; var void *var_448h @ stack - 0x448
|           ; var int64_t var_440h @ stack - 0x440
|           ; var int64_t var_3c0h @ stack - 0x3c0
|           ; var int64_t var_340h @ stack - 0x340
|           ; var int64_t var_2c0h @ stack - 0x2c0
|           ; var int64_t var_240h @ stack - 0x240
|           ; var int64_t var_1c0h @ stack - 0x1c0
|           ; var int64_t var_140h @ stack - 0x140
|           ; var int64_t var_78h @ stack - 0x78
|           ; var int64_t var_60h @ stack - 0x60
|           ; var int64_t var_58h @ stack - 0x58
|           ; var int64_t var_50h @ stack - 0x50
|           ; var int64_t var_48h @ stack - 0x48
|           ; var int64_t var_40h @ stack - 0x40
|           ; var int64_t var_38h @ stack - 0x38
|           ; var int64_t var_30h @ stack - 0x30
|           ; var int64_t var_28h @ stack - 0x28
|           ; var int64_t var_20h @ stack - 0x20
|           ; var int64_t var_18h @ stack - 0x18
|           ; var int64_t var_10h @ stack - 0x10
|           ; var int64_t var_8h @ stack - 0x8
|           0x100005990      pacibsp
|           0x100005994      stp   x28, x27, [var_60h]!
|           0x100005998      stp   x26, x25, [var_50h]
|           0x10000599c      stp   x24, x23, [var_40h]
|           0x1000059a0      stp   x22, x21, [var_30h]
|           0x1000059a4      stp   x20, x19, [var_20h]
|           0x1000059a8      stp   x29, x30, [var_10h]
|           0x1000059ac      add   x29, sp, 0x50
|           0x1000059b0      sub   sp, sp, 0x690
|           0x1000059b4      str   x1, [var_5f8h]                      ; arg2
|           0x1000059b8      str   w0, [var_600h]                      ; arg1
|           0x1000059bc      add   x20, var_550h
|           0x1000059c0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x1000059c4      ldr   x8, [x8, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x1000059c8      ldr   x8, [x8]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x1000059cc      stur  x8, [var_78h + 0x10]
|           0x1000059d0      bl    sym.imp.objc_autoreleasePoolPush
|           0x1000059d4      str   x0, [var_6d8h]
|           0x1000059d8      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x1000059dc      add   x8, x8, 0                           ; 0x10000c000 ; "_\U0000007f"
|           0x1000059e0      ldp   q0, q1, [x8, 0x80]
|           0x1000059e4      str   q0, [x20, 0x490]
|           0x1000059e8      str   q1, [x20, 0x4a0]
|           0x1000059ec      ldp   q0, q1, [x8, 0xa0]
|           0x1000059f0      str   q0, [x20, 0x4b0]
|           0x1000059f4      str   q1, [x20, 0x4c0]
|           0x1000059f8      ldp   q0, q1, [x8, 0x40]
|           0x1000059fc      str   q0, [x20, 0x450]
|           0x100005a00      str   q1, [x20, 0x460]
|           0x100005a04      ldp   q0, q1, [x8, 0x60]
|           0x100005a08      str   q0, [x20, 0x470]
|           0x100005a0c      str   q1, [x20, 0x480]
|           0x100005a10      ldp   q0, q1, [x8]                        ; [0x10000c000:4]=0x7f5f ; "_\U0000007f"
|           0x100005a14      str   q0, [x20, 0x410]
|           0x100005a18      str   q1, [x20, 0x420]
|           0x100005a1c      ldp   q0, q1, [x8, 0x20]
|           0x100005a20      str   q0, [x20, 0x430]
|           0x100005a24      str   wzr, [var_450h]
|           0x100005a28      str   q1, [x20, 0x440]
|           0x100005a2c      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
|           0x100005a30      ldr   x0, [x19, 0xc28]                    ; [0x10000cc28:4]=0x1c190 ; reloc.NSMutableArray
|           0x100005a34      mov   w2, 0x10
|           0x100005a38      bl    stub.objc_msgSend_arrayWithCapacity: ;  stub.objc_msgSend_arrayWithCapacity:(void)
|           0x100005a3c      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100005a40      str   x0, [var_678h]
|           0x100005a44      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100005a48      ldr   x0, [x8, 0xc30]                     ; [0x10000cc30:4]=0x1c198 ; reloc.NSMutableDictionary
|           0x100005a4c      mov   w2, 0x10
|           0x100005a50      bl    stub.objc_msgSend_dictionaryWithCapacity: ;  stub.objc_msgSend_dictionaryWithCapacity:(void)
|           0x100005a54      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100005a58      str   x0, [var_6c0h]
|           0x100005a5c      ldr   x0, [x19, 0xc28]                    ; [0x10000cc28:4]=0x1c190 ; reloc.NSMutableArray
|           0x100005a60      mov   w2, 0x10
|           0x100005a64      bl    stub.objc_msgSend_arrayWithCapacity: ;  stub.objc_msgSend_arrayWithCapacity:(void)
|           0x100005a68      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100005a6c      str   x0, [var_6b8h]
|           0x100005a70      ldr   x0, [x19, 0xc28]                    ; [0x10000cc28:4]=0x1c190 ; reloc.NSMutableArray
|           0x100005a74      mov   w2, 3
|           0x100005a78      bl    stub.objc_msgSend_arrayWithCapacity: ;  stub.objc_msgSend_arrayWithCapacity:(void)
|           0x100005a7c      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100005a80      str   x0, [var_6c8h]
|           0x100005a84      ldr   x0, [x19, 0xc28]                    ; [0x10000cc28:4]=0x1c190 ; reloc.NSMutableArray
|           0x100005a88      mov   w2, 3
|           0x100005a8c      bl    stub.objc_msgSend_arrayWithCapacity: ;  stub.objc_msgSend_arrayWithCapacity:(void)
|           0x100005a90      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100005a94      str   x0, [var_6a8h]
|           0x100005a98      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100005a9c      ldr   x8, [x8, 0xc40]                     ; [0x10000cc40:4]=0x1c1a8 ; reloc.kIOMasterPortDefault
|           0x100005aa0      ldr   w0, [x8]                            ; [0x10001c1a8:4]=0
|                                                                      ; str.const
|           0x100005aa4      adrp  x1, data.100007000                  ; 0x100007000
|           0x100005aa8      add   x1, x1, 0xf92                       ; 0x100007f92 ; "IODeviceTree:/options"
|           0x100005aac      str   w0, [var_5f0h]
|           0x100005ab0      bl    sym.imp.IORegistryEntryFromPath
|           0x100005ab4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100005ab8      ldr   x8, [x8, 0xc38]                     ; [0x10000cc38:4]=0x1c1a0 ; reloc.kCFAllocatorDefault
|           0x100005abc      ldr   x2, [x8]                            ; [0x10001c1a0:4]=0
|                                                                      ; reloc.target.kCFAllocatorDefault
|           0x100005ac0      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100005ac4      add   x1, x1, 0x640                       ; 0x10000c640
|                                                                      ; reloc.__CFConstantStringClassReference.10000c640
|           0x100005ac8      str   x2, [var_5e8h]
|           0x100005acc      mov   w3, 0
|           0x100005ad0      bl    sym.imp.IORegistryEntryCreateCFProperty
|           0x100005ad4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100005ad8      add   x2, x2, 0x660                       ; 0x10000c660
|                                                                      ; reloc.__CFConstantStringClassReference.10000c660
|           0x100005adc      str   x0, [instance]
|           0x100005ae0      bl    stub.objc_msgSend_componentsSeparatedByString: ;  stub.objc_msgSend_componentsSeparatedByString:(void)
|           0x100005ae4      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100005ae8      movi  v0.2d, 0000000000000000
|           0x100005aec      stp   q0, q0, [x20, 0xc0]
|           0x100005af0      stp   q0, q0, [x20, 0xe0]
|           0x100005af4      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100005af8      mov   x24, x0
|           0x100005afc      add   x2, var_490h
|           0x100005b00      add   x3, var_1c0h
|           0x100005b04      mov   w4, 0x10
|           0x100005b08      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|       ,=< 0x100005b0c      cbz   x0, 0x100005c00
|       |   0x100005b10      mov   x26, x0
|       |   0x100005b14      ldr   x8, [var_480h]                      ; [0x270:4]=-1 ; 624
|       |   0x100005b18      ldr   x20, [x8]
|       |   0x100005b1c      adrp  x25, section.7.__DATA_CONST.__const ; 0x10000c000
|       |   0x100005b20      add   x25, x25, 0x680                     ; 0x10000c680
|       |                                                              ; reloc.__CFConstantStringClassReference.10000c680
|       |   0x100005b24      adrp  x27, section.7.__DATA_CONST.__const ; 0x10000c000
|       |   0x100005b28      add   x27, x27, 0x6a0                     ; 0x10000c6a0
|       |                                                              ; reloc.__CFConstantStringClassReference.10000c6a0
|       |   0x100005b2c      adrp  x28, section.7.__DATA_CONST.__const ; 0x10000c000
|       |   0x100005b30      add   x28, x28, 0x6c0                     ; 0x10000c6c0
|       |                                                              ; reloc.__CFConstantStringClassReference.10000c6c0
|      .--> 0x100005b34      mov   x19, 0
|     .---> 0x100005b38      ldr   x8, [var_480h]                      ; [0x270:4]=-1 ; 624
|     ::|   0x100005b3c      ldr   x8, [x8]
|     ::|   0x100005b40      cmp   x8, x20
|    ,====< 0x100005b44      b.eq  0x100005b50
|    |::|   0x100005b48      mov   x0, x24                             ; void *instance
|    |::|   0x100005b4c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
|    `----> 0x100005b50      ldr   x8, [var_488h]                      ; [0x268:4]=-1 ; 616
|     ::|   0x100005b54      ldr   x0, [x8, x19, lsl 3]
|     ::|   0x100005b58      mov   x2, x25
|     ::|   0x100005b5c      bl    stub.objc_msgSend_componentsSeparatedByString: ;  stub.objc_msgSend_componentsSeparatedByString:(void)
|     ::|   0x100005b60      bl    sym.imp.objc_claimAutoreleasedReturnValue
|     ::|   0x100005b64      mov   x21, x0
|     ::|   0x100005b68      mov   x2, 0
|     ::|   0x100005b6c      bl    stub.objc_msgSend_objectAtIndexedSubscript: ;  stub.objc_msgSend_objectAtIndexedSubscript:(void)
|     ::|   0x100005b70      bl    sym.imp.objc_claimAutoreleasedReturnValue
|     ::|   0x100005b74      mov   x22, x0
|    ,====< 0x100005b78      cbz   x0, 0x100005bc8
|    |::|   0x100005b7c      mov   x0, x22
|    |::|   0x100005b80      mov   x2, x27
|    |::|   0x100005b84      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
|   ,=====< 0x100005b88      cbnz  x0, 0x100005bc8
|   ||::|   0x100005b8c      mov   x0, x21
|   ||::|   0x100005b90      mov   w2, 1
|   ||::|   0x100005b94      bl    stub.objc_msgSend_objectAtIndexedSubscript: ;  stub.objc_msgSend_objectAtIndexedSubscript:(void)
|   ||::|   0x100005b98      bl    sym.imp.objc_claimAutoreleasedReturnValue
|   ||::|   0x100005b9c      mov   x23, x0
|  ,======< 0x100005ba0      cbz   x0, 0x100005bc0
|  |||::|   0x100005ba4      mov   x0, x23
|  |||::|   0x100005ba8      mov   x2, x28
|  |||::|   0x100005bac      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ,=======< 0x100005bb0      cbz   x0, 0x100005bc0
| ||||::|   0x100005bb4      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
| ||||::|   0x100005bb8      mov   w9, 1
| ||||::|   0x100005bbc      strb  w9, [x8, 0x179]
| ``------> 0x100005bc0      mov   x0, x23                             ; void *instance
|   ||::|   0x100005bc4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   ``----> 0x100005bc8      mov   x0, x22                             ; void *instance
|     ::|   0x100005bcc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     ::|   0x100005bd0      mov   x0, x21                             ; void *instance
|     ::|   0x100005bd4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|     ::|   0x100005bd8      add   x19, x19, 1
|     ::|   0x100005bdc      subs  x26, x26, 1
|     `===< 0x100005be0      b.ne  0x100005b38
|      :|   0x100005be4      add   x2, var_490h
|      :|   0x100005be8      add   x3, var_1c0h
|      :|   0x100005bec      mov   x0, x24
|      :|   0x100005bf0      mov   w4, 0x10
|      :|   0x100005bf4      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|      :|   0x100005bf8      mov   x26, x0
|      `==< 0x100005bfc      cbnz  x0, 0x100005b34
|       `-> 0x100005c00      str   xzr, [var_448h]
|           0x100005c04      strb  wzr, [var_449h]
|           0x100005c08      mov   x0, x24                             ; void *instance
|           0x100005c0c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005c10      mov   x0, x24                             ; void *instance
|           0x100005c14      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005c18      ldr   x0, [instance]                      ; [0x110:4]=-1 ; 272 ; void *instance
|           0x100005c1c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100005c20      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
|           0x100005c24      ldrb  w8, [x8, 0x179]                     ; [0x179:4]=-1 ; 377
|       ,=< 0x100005c28      tbnz  w8, 0, 0x100005cfc
|       |   0x100005c2c      adrp  x1, data.100007000                  ; 0x100007000
|       |   0x100005c30      add   x1, x1, 0xf92                       ; 0x100007f92 ; "IODeviceTree:/options"
|       |   0x100005c34      ldr   w0, [var_5f0h]                      ; [0x100:4]=-1 ; 256
|       |   0x100005c38      bl    sym.imp.IORegistryEntryFromPath
|       |   0x100005c3c      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|       |   0x100005c40      add   x1, x1, 0x6a0                       ; 0x10000c6a0
|       |                                                              ; reloc.__CFConstantStringClassReference.10000c6a0
|       |   0x100005c44      ldr   x2, [var_5e8h]                      ; [0x108:4]=-1 ; 264
|       |   0x100005c48      mov   w3, 0
|       |   0x100005c4c      bl    sym.imp.IORegistryEntryCreateCFProperty
|       |   0x100005c50      mov   x23, x0
|       |   0x100005c54      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|       |   0x100005c58      ldr   x0, [x8, 0xc18]                     ; [0x10000cc18:4]=0x1c180 ; reloc.NSData
|       |   0x100005c5c      bl    sym.imp.objc_opt_class
|       |   0x100005c60      mov   x1, x0
|       |   0x100005c64      mov   x0, x23
|       |   0x100005c68      bl    sym.imp.objc_opt_isKindOfClass
|       |   0x100005c6c      mov   x8, x0
|       |   0x100005c70      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
|       |   0x100005c74      ldr   x0, [x9, 0xbe8]                     ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
|      ,==< 0x100005c78      tbz   w8, 0, 0x100005c90
|      ||   0x100005c7c      bl    sym.imp.objc_alloc
|      ||   0x100005c80      mov   x2, x23
|      ||   0x100005c84      mov   w3, 4
|      ||   0x100005c88      bl    stub.objc_msgSend_initWithData:encoding: ;  stub.objc_msgSend_initWithData:encoding:(void)
|     ,===< 0x100005c8c      b     0x100005cac
|     |`--> 0x100005c90      bl    sym.imp.objc_opt_class
|     | |   0x100005c94      mov   x1, x0
|     | |   0x100005c98      mov   x0, x23
|     | |   0x100005c9c      bl    sym.imp.objc_opt_isKindOfClass
|     |,==< 0x100005ca0      tbz   w0, 0, 0x100005cd8
|     |||   0x100005ca4      mov   x0, x23                             ; void *instance
|     |||   0x100005ca8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|     |||   ; CODE XREF from entry0 @ 0x100005c8c
|     `---> 0x100005cac      mov   x21, x0
|     ,===< 0x100005cb0      cbz   x0, 0x100005cdc
|     |||   0x100005cb4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|     |||   0x100005cb8      add   x2, x2, 0x6c0                       ; 0x10000c6c0
|     |||                                                              ; reloc.__CFConstantStringClassReference.10000c6c0
|     |||   0x100005cbc      mov   x0, x21
|     |||   0x100005cc0      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
|    ,====< 0x100005cc4      cbz   x0, 0x100005cdc
|    ||||   0x100005cc8      mov   w8, 1
|    ||||   0x100005ccc      adrp  x9, section.12.__DATA.__objc_selrefs ; 0x100010000
|    ||||   0x100005cd0      strb  w8, [x9, 0x179]
|   ,=====< 0x100005cd4      b     0x100005cdc
|   |||`--> 0x100005cd8      mov   x21, 0
|   ||| |   ; CODE XREF from entry0 @ 0x100005cd4
|   ```---> 0x100005cdc      mov   x0, x21                             ; void *instance
|       |   0x100005ce0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|       |   0x100005ce4      mov   x0, x23                             ; void *instance
|       |   0x100005ce8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|       |   0x100005cec      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
|       |   0x100005cf0      ldrb  w8, [x8, 0x179]                     ; [0x179:4]=-1 ; 377
|       |   0x100005cf4      cmp   w8, 1
|      ,==< 0x100005cf8      b.ne  0x100005dbc
|      |`-> 0x100005cfc      adrp  x0, data.100008000                  ; 0x100008000
|      |    0x100005d00      add   x0, x0, 0x54b                       ; 0x10000854b ; "USB-C Updates bypassed because usbcupdater_bypass_usbc_updates boot arg was set" ; const char *s
|      |    0x100005d04      bl    sym.imp.puts                        ; int puts(const char *s)
|      |    0x100005d08      mov   w19, 0
|      |    0x100005d0c      mov   x21, 0
|      |    0x100005d10      mov   x25, 0
|      |    0x100005d14      mov   x22, 0
|      |    0x100005d18      mov   x23, 0
|      |    0x100005d1c      mov   x26, 0
|      |    0x100005d20      ldr   x27, [var_678h]                     ; [0x78:4]=-1 ; 120
|      |    0x100005d24      ldp   x28, x20, [var_6c0h]
|      |    ; CODE XREF from entry0 @ 0x1000072a4
|    ..-.-> 0x100005d28      mov   x0, x26                             ; void *instance
|    ::|:   0x100005d2c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d30      ldr   x0, [var_6a8h]                      ; [0x48:4]=-1 ; 72 ; void *instance
|    ::|:   0x100005d34      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d38      ldr   x0, [var_6c8h]                      ; [0x28:4]=-1 ; 40 ; void *instance
|    ::|:   0x100005d3c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d40      mov   x0, x20                             ; void *instance
|    ::|:   0x100005d44      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d48      mov   x0, x28                             ; void *instance
|    ::|:   0x100005d4c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d50      mov   x0, x27                             ; void *instance
|    ::|:   0x100005d54      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d58      mov   x0, x23                             ; void *instance
|    ::|:   0x100005d5c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d60      mov   x0, x22                             ; void *instance
|    ::|:   0x100005d64      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d68      mov   x0, x25                             ; void *instance
|    ::|:   0x100005d6c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d70      mov   x0, x21                             ; void *instance
|    ::|:   0x100005d74      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|    ::|:   0x100005d78      ldr   x0, [var_6d8h]                      ; [0x18:4]=-1 ; 24
|    ::|:   0x100005d7c      bl    sym.imp.objc_autoreleasePoolPop
|    ::|:   0x100005d80      ldur  x8, [var_78h + 0x10]
|    ::|:   0x100005d84      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
|    ::|:   0x100005d88      ldr   x9, [x9, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|    ::|:   0x100005d8c      ldr   x9, [x9]                            ; [0x10001c158:4]=0
|    ::|:                                                              ; str.objc_stubs
|    ::|:   0x100005d90      cmp   x9, x8
|   ,=====< 0x100005d94      b.ne  0x100006034
|   |::|:   0x100005d98      mov   x0, x19
|   |::|:   0x100005d9c      add   sp, sp, 0x690
|   |::|:   0x100005da0      ldp   x29, x30, [var_10h]
|   |::|:   0x100005da4      ldp   x20, x19, [var_20h]
|   |::|:   0x100005da8      ldp   x22, x21, [var_30h]
|   |::|:   0x100005dac      ldp   x24, x23, [var_40h]
|   |::|:   0x100005db0      ldp   x26, x25, [var_50h]
|   |::|:   0x100005db4      ldp   x28, x27, [sp], 0x60
|   |::|:   0x100005db8      retab
|   |::`--> 0x100005dbc      adrp  x1, data.100007000                  ; 0x100007000
|   |:: :   0x100005dc0      add   x1, x1, 0xf92                       ; 0x100007f92 ; "IODeviceTree:/options"
|   |:: :   0x100005dc4      ldr   w0, [var_5f0h]                      ; [0x100:4]=-1 ; 256
|   |:: :   0x100005dc8      bl    sym.imp.IORegistryEntryFromPath
|   |:: :   0x100005dcc      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|   |:: :   0x100005dd0      add   x1, x1, 0x640                       ; 0x10000c640
|   |:: :                                                              ; reloc.__CFConstantStringClassReference.10000c640
|   |:: :   0x100005dd4      ldr   x2, [var_5e8h]                      ; [0x108:4]=-1 ; 264
|   |:: :   0x100005dd8      mov   w3, 0
|   |:: :   0x100005ddc      bl    sym.imp.IORegistryEntryCreateCFProperty
|   |:: :   0x100005de0      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|   |:: :   0x100005de4      add   x2, x2, 0x660                       ; 0x10000c660
|   |:: :                                                              ; reloc.__CFConstantStringClassReference.10000c660
|   |:: :   0x100005de8      str   x0, [instance]
|   |:: :   0x100005dec      bl    stub.objc_msgSend_componentsSeparatedByString: ;  stub.objc_msgSend_componentsSeparatedByString:(void)
|   |:: :   0x100005df0      bl    sym.imp.objc_claimAutoreleasedReturnValue
|   |:: :   0x100005df4      movi  v0.2d, 0000000000000000
|   |:: :   0x100005df8      add   x8, var_550h
|   |:: :   0x100005dfc      stp   q0, q0, [x8, 0x80]
|   |:: :   0x100005e00      stp   q0, q0, [x8, 0xa0]
|   |:: :   0x100005e04      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|   |:: :   0x100005e08      mov   x24, x0
|   |:: :   0x100005e0c      add   x2, var_4d0h
|   |:: :   0x100005e10      add   x3, var_240h
|   |:: :   0x100005e14      mov   w4, 0x10
|   |:: :   0x100005e18      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|   |::,==< 0x100005e1c      cbz   x0, 0x100005f10
|   |::|:   0x100005e20      mov   x26, x0
|   |::|:   0x100005e24      ldr   x8, [var_4c0h]                      ; [0x230:4]=-1 ; 560
|   |::|:   0x100005e28      ldr   x20, [x8]
|   |::|:   0x100005e2c      adrp  x25, section.7.__DATA_CONST.__const ; 0x10000c000
|   |::|:   0x100005e30      add   x25, x25, 0x680                     ; 0x10000c680
|   |::|:                                                              ; reloc.__CFConstantStringClassReference.10000c680
|   |::|:   0x100005e34      adrp  x27, section.7.__DATA_CONST.__const ; 0x10000c000
|   |::|:   0x100005e38      add   x27, x27, 0x6e0                     ; 0x10000c6e0
|   |::|:                                                              ; reloc.__CFConstantStringClassReference.10000c6e0
|   |::|:   0x100005e3c      adrp  x28, section.7.__DATA_CONST.__const ; 0x10000c000
|   |::|:   0x100005e40      add   x28, x28, 0x6c0                     ; 0x10000c6c0
|   |::|:                                                              ; reloc.__CFConstantStringClassReference.10000c6c0
|  .------> 0x100005e44      mov   x19, 0
| .-------> 0x100005e48      ldr   x8, [var_4c0h]                      ; [0x230:4]=-1 ; 560
| ::|::|:   0x100005e4c      ldr   x8, [x8]
| ::|::|:   0x100005e50      cmp   x8, x20
| ========< 0x100005e54      b.eq  0x100005e60
| ::|::|:   0x100005e58      mov   x0, x24                             ; void *instance
| ::|::|:   0x100005e5c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100005e60      ldr   x8, [var_4c8h]                      ; [0x228:4]=-1 ; 552
| ::|::|:   0x100005e64      ldr   x0, [x8, x19, lsl 3]
| ::|::|:   0x100005e68      mov   x2, x25
| ::|::|:   0x100005e6c      bl    stub.objc_msgSend_componentsSeparatedByString: ;  stub.objc_msgSend_componentsSeparatedByString:(void)
| ::|::|:   0x100005e70      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::|::|:   0x100005e74      mov   x21, x0
| ::|::|:   0x100005e78      mov   x2, 0
| ::|::|:   0x100005e7c      bl    stub.objc_msgSend_objectAtIndexedSubscript: ;  stub.objc_msgSend_objectAtIndexedSubscript:(void)
| ::|::|:   0x100005e80      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::|::|:   0x100005e84      mov   x22, x0
| ========< 0x100005e88      cbz   x0, 0x100005ed8
| ::|::|:   0x100005e8c      mov   x0, x22
| ::|::|:   0x100005e90      mov   x2, x27
| ::|::|:   0x100005e94      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100005e98      cbnz  x0, 0x100005ed8
| ::|::|:   0x100005e9c      mov   x0, x21
| ::|::|:   0x100005ea0      mov   w2, 1
| ::|::|:   0x100005ea4      bl    stub.objc_msgSend_objectAtIndexedSubscript: ;  stub.objc_msgSend_objectAtIndexedSubscript:(void)
| ::|::|:   0x100005ea8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::|::|:   0x100005eac      mov   x23, x0
| ========< 0x100005eb0      cbz   x0, 0x100005ed0
| ::|::|:   0x100005eb4      mov   x0, x23
| ::|::|:   0x100005eb8      mov   x2, x28
| ::|::|:   0x100005ebc      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100005ec0      cbz   x0, 0x100005ed0
| ::|::|:   0x100005ec4      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
| ::|::|:   0x100005ec8      mov   w9, 1
| ::|::|:   0x100005ecc      strb  w9, [x8, 0x178]
| --------> 0x100005ed0      mov   x0, x23                             ; void *instance
| ::|::|:   0x100005ed4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| --------> 0x100005ed8      mov   x0, x22                             ; void *instance
| ::|::|:   0x100005edc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::|::|:   0x100005ee0      mov   x0, x21                             ; void *instance
| ::|::|:   0x100005ee4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::|::|:   0x100005ee8      add   x19, x19, 1
| ::|::|:   0x100005eec      subs  x26, x26, 1
| `=======< 0x100005ef0      b.ne  0x100005e48
|  :|::|:   0x100005ef4      add   x2, var_4d0h
|  :|::|:   0x100005ef8      add   x3, var_240h
|  :|::|:   0x100005efc      mov   x0, x24
|  :|::|:   0x100005f00      mov   w4, 0x10
|  :|::|:   0x100005f04      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|  :|::|:   0x100005f08      mov   x26, x0
|  `======< 0x100005f0c      cbnz  x0, 0x100005e44
|   |::`--> 0x100005f10      mov   x0, x24                             ; void *instance
|   |:: :   0x100005f14      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |:: :   0x100005f18      mov   x0, x24                             ; void *instance
|   |:: :   0x100005f1c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |:: :   0x100005f20      ldr   x0, [instance]                      ; [0x110:4]=-1 ; 272 ; void *instance
|   |:: :   0x100005f24      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |:: :   0x100005f28      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
|   |:: :   0x100005f2c      ldrb  w8, [x8, 0x178]                     ; [0x100010178:4]=0
|   |:: :                                                              ; section.13.__DATA.__common
|   |::,==< 0x100005f30      tbz   w8, 0, 0x100005f50
|   |::|:   0x100005f34      mov   x25, 0
|   |::|:   0x100005f38      str   wzr, [var_694h]
|   |::|:   0x100005f3c      ldr   x27, [var_678h]                     ; [0x78:4]=-1 ; 120
|   |::|:   0x100005f40      ldr   x28, [var_6c0h]                     ; [0x30:4]=-1 ; 48
|   |::|:   0x100005f44      ldr   x20, [var_5f8h]                     ; [0xf8:4]=-1 ; 248
|   |::|:   0x100005f48      ldr   w23, [var_600h]                     ; [0xf0:4]=-1 ; 240
|  ,======< 0x100005f4c      b     0x10000604c
|  ||::`--> 0x100005f50      adrp  x1, data.100007000                  ; 0x100007000
|  ||:: :   0x100005f54      add   x1, x1, 0xf92                       ; 0x100007f92 ; "IODeviceTree:/options"
|  ||:: :   0x100005f58      ldr   w0, [var_5f0h]                      ; [0x100:4]=-1 ; 256
|  ||:: :   0x100005f5c      bl    sym.imp.IORegistryEntryFromPath
|  ||:: :   0x100005f60      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||:: :   0x100005f64      add   x1, x1, 0x6e0                       ; 0x10000c6e0
|  ||:: :                                                              ; reloc.__CFConstantStringClassReference.10000c6e0
|  ||:: :   0x100005f68      ldr   x2, [var_5e8h]                      ; [0x108:4]=-1 ; 264
|  ||:: :   0x100005f6c      mov   w3, 0
|  ||:: :   0x100005f70      bl    sym.imp.IORegistryEntryCreateCFProperty
|  ||:: :   0x100005f74      mov   x21, x0
|  ||:: :   0x100005f78      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||:: :   0x100005f7c      ldr   x0, [x8, 0xc18]                     ; [0x10000cc18:4]=0x1c180 ; reloc.NSData
|  ||:: :   0x100005f80      bl    sym.imp.objc_opt_class
|  ||:: :   0x100005f84      mov   x1, x0
|  ||:: :   0x100005f88      mov   x0, x21
|  ||:: :   0x100005f8c      bl    sym.imp.objc_opt_isKindOfClass
|  ||:: :   0x100005f90      mov   x8, x0
|  ||:: :   0x100005f94      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||:: :   0x100005f98      ldr   x0, [x9, 0xbe8]                     ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
|  ||:: :   0x100005f9c      ldr   x20, [var_5f8h]                     ; [0xf8:4]=-1 ; 248
|  ||:: :   0x100005fa0      ldr   w23, [var_600h]                     ; [0xf0:4]=-1 ; 240
|  ||::,==< 0x100005fa4      tbz   w8, 0, 0x100005fcc
|  ||::|:   0x100005fa8      bl    sym.imp.objc_alloc
|  ||::|:   0x100005fac      mov   x2, x21
|  ||::|:   0x100005fb0      mov   w3, 4
|  ||::|:   0x100005fb4      bl    stub.objc_msgSend_initWithData:encoding: ;  stub.objc_msgSend_initWithData:encoding:(void)
|  ||::|:   0x100005fb8      mov   x25, x0
|  ||::|:   0x100005fbc      ldr   x27, [var_678h]                     ; [0x78:4]=-1 ; 120
|  ||::|:   0x100005fc0      ldr   x28, [var_6c0h]                     ; [0x30:4]=-1 ; 48
| ,=======< 0x100005fc4      cbnz  x25, 0x100005ff8
| ========< 0x100005fc8      b     0x100006028
| |||::`--> 0x100005fcc      bl    sym.imp.objc_opt_class
| |||:: :   0x100005fd0      mov   x1, x0
| |||:: :   0x100005fd4      mov   x0, x21
| |||:: :   0x100005fd8      bl    sym.imp.objc_opt_isKindOfClass
| |||:: :   0x100005fdc      ldr   x27, [var_678h]                     ; [0x78:4]=-1 ; 120
| |||:: :   0x100005fe0      ldr   x28, [var_6c0h]                     ; [0x30:4]=-1 ; 48
| |||::,==< 0x100005fe4      tbz   w0, 0, 0x100006024
| |||::|:   0x100005fe8      mov   x0, x21                             ; void *instance
| |||::|:   0x100005fec      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||::|:   0x100005ff0      mov   x25, x0
| ========< 0x100005ff4      cbz   x25, 0x100006028
| `-------> 0x100005ff8      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x100005ffc      add   x2, x2, 0x6c0                       ; 0x10000c6c0
|  ||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c6c0
|  ||::|:   0x100006000      mov   x0, x25
|  ||::|:   0x100006004      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ,=======< 0x100006008      cbz   x0, 0x100006028
| |||::|:   0x10000600c      mov   x22, 0
| |||::|:   0x100006010      str   wzr, [var_694h]
| |||::|:   0x100006014      mov   w8, 1
| |||::|:   0x100006018      adrp  x9, section.12.__DATA.__objc_selrefs ; 0x100010000
| |||::|:   0x10000601c      strb  w8, [x9, 0x178]
| ========< 0x100006020      b     0x100006038
| |||::`--> 0x100006024      mov   x25, 0
| |||:: :   ; CODE XREF from entry0 @ 0x100005fc8
| `-------> 0x100006028      mov   x22, 0
|  ||:: :   0x10000602c      str   wzr, [var_694h]
|  ||::,==< 0x100006030      b     0x100006038
|  |`-----> 0x100006034      bl    sym.imp.__stack_chk_fail            ; void __stack_chk_fail(void)
|  | ::|:   ; CODE XREFS from entry0 @ 0x100006020, 0x100006030, 0x100006230
| --.--`--> 0x100006038      mov   x0, x25                             ; void *instance
|  |::: :   0x10000603c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |::: :   0x100006040      mov   x0, x21                             ; void *instance
|  |::: :   0x100006044      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |::: :   0x100006048      mov   x25, x22
|  |::: :   ; CODE XREF from entry0 @ 0x100005f4c
|  `------> 0x10000604c      adrp  x21, data.100007000                 ; 0x100007000
|   ::: :   0x100006050      add   x21, x21, 0xff7                     ; 0x100007ff7 ; "vp:Xs"
|   ::: :   0x100006054      mov   w19, 1
|   ::: :   ; CODE XREFS from entry0 @ 0x100006090, 0x1000060b4
| ..---.--> 0x100006058      add   x3, var_140h
| :::::::   0x10000605c      add   x4, var_450h
| :::::::   0x100006060      mov   x0, x23
| :::::::   0x100006064      mov   x1, x20
| :::::::   0x100006068      mov   x2, x21
| :::::::   0x10000606c      bl    sym.imp.getopt_long
| :::::::   0x100006070      cmp   w0, 0x6f                            ; 'o'
| ========< 0x100006074      b.gt  0x100006094
| :::::::   0x100006078      cmp   w0, 0x58                            ; 'X'
| ========< 0x10000607c      b.eq  0x100006058
| :::::::   0x100006080      cmp   w0, 0x62                            ; 'b'
| ========< 0x100006084      b.ne  0x1000060b8
| :::::::   0x100006088      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
| :::::::   0x10000608c      strb  w19, [x8, 0x178]
| `=======< 0x100006090      b     0x100006058
| --------> 0x100006094      cmp   w0, 0x73                            ; 's'
|  `======< 0x100006098      b.eq  0x100006058
|   :::::   0x10000609c      cmp   w0, 0x70                            ; 'p'
|  ,======< 0x1000060a0      b.eq  0x1000061e4
|  |:::::   0x1000060a4      cmp   w0, 0x76                            ; 'v'
| ,=======< 0x1000060a8      b.ne  0x100006234
| ||:::::   0x1000060ac      mov   w8, 1
| ||:::::   0x1000060b0      str   w8, [var_694h]
| ||:::`==< 0x1000060b4      b     0x100006058
| --------> 0x1000060b8      cmn   w0, 1
| ||:::,==< 0x1000060bc      b.ne  0x100006234
| ||:::|:   0x1000060c0      add   x0, var_448h                        ; int64_t arg1
| ||:::|:   0x1000060c4      add   x1, var_449h                        ; int64_t arg2
| ||:::|:   0x1000060c8      bl    sym.func.100000a2c
| ||:::|:   0x1000060cc      bl    sym.func.1000008d0
| ||:::|:   0x1000060d0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:::|:   0x1000060d4      mov   x21, x0
| ||:::|:   0x1000060d8      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
| ========< 0x1000060dc      tbz   w8, 0, 0x100006288
| ||:::|:   0x1000060e0      mov   w0, 0xa
| ||:::|:   0x1000060e4      bl    sym.imp.putchar                     ; int putchar(int c)
| ||:::|:   0x1000060e8      ldr   x8, [var_448h]                      ; [0x2a8:4]=-1 ; 680
| ||:::|:   0x1000060ec      str   x8, [sp]
| ||:::|:   0x1000060f0      adrp  x0, data.100008000                  ; 0x100008000
| ||:::|:   0x1000060f4      add   x0, x0, 0x10                        ; 0x100008010 ; "Board ID:                %llX\n" ; const char *format
| ||:::|:   0x1000060f8      bl    sym.imp.printf                      ; int printf(const char *format)
| ||:::|:   0x1000060fc      mov   x0, x21
| ||:::|:   0x100006100      bl    sym.imp.objc_retainAutorelease
| ||:::|:   0x100006104      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| ||:::|:   0x100006108      str   x0, [sp]
| ||:::|:   0x10000610c      adrp  x0, data.100008000                  ; 0x100008000
| ||:::|:   0x100006110      add   x0, x0, 0x2f                        ; 0x10000802f ; "Board ID String:         %s\n" ; const char *format
| ||:::|:   0x100006114      bl    sym.imp.printf                      ; int printf(const char *format)
| ||:::|:   0x100006118      ldrb  w8, [var_449h]                      ; [0x2a7:4]=-1 ; 679
| ||:::|:   0x10000611c      str   x8, [sp]
| ||:::|:   0x100006120      adrp  x0, data.100008000                  ; 0x100008000
| ||:::|:   0x100006124      add   x0, x0, 0x4c                        ; 0x10000804c ; "Board Revision:          %u\n" ; const char *format
| ||:::|:   0x100006128      bl    sym.imp.printf                      ; int printf(const char *format)
| ||:::|:   0x10000612c      mov   w0, 0xa
| ||:::|:   0x100006130      bl    sym.imp.putchar                     ; int putchar(int c)
| ||:::|:   0x100006134      mov   x0, x25
| ||:::|:   0x100006138      bl    sym.imp.objc_retainAutorelease
| ||:::|:   0x10000613c      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| ||:::|:   0x100006140      str   x0, [sp]
| ||:::|:   0x100006144      adrp  x0, data.100008000                  ; 0x100008000
| ||:::|:   0x100006148      add   x0, x0, 0x69                        ; 0x100008069 ; "Personalities Directory: %s\n" ; const char *format
| ||:::|:   0x10000614c      bl    sym.imp.printf                      ; int printf(const char *format)
| ||:::|:   0x100006150      adrp  x0, data.100008000                  ; 0x100008000
| ||:::|:   0x100006154      add   x0, x0, 0x50c                       ; const char *s
| ||:::|:   0x100006158      bl    sym.imp.puts                        ; int puts(const char *s)
| ||:::|:   0x10000615c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:::|:   0x100006160      ldr   x8, [x8, 0xc00]                     ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
| ||:::|:   0x100006164      ldr   x0, [x8]                            ; [0x10001c168:4]=0
| ||:::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| ||:::|:   0x100006168      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| ||:::|:   0x10000616c      bl    sym.func.100001544
| ||:::|:   0x100006170      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:::|:   0x100006174      mov   x19, x0
| ========< 0x100006178      cbz   x0, 0x100006188
| ||:::|:   0x10000617c      mov   x0, x19
| ||:::|:   0x100006180      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
| ========< 0x100006184      cbnz  x0, 0x1000061a4
| --------> 0x100006188      bl    sym.func.1000013c4
| ||:::|:   0x10000618c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:::|:   0x100006190      mov   x20, x0
| ||:::|:   0x100006194      mov   x0, x19                             ; void *instance
| ||:::|:   0x100006198      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||:::|:   0x10000619c      mov   x19, x20
| ========< 0x1000061a0      cbz   x20, 0x100006250
| --------> 0x1000061a4      mov   x0, x19
| ||:::|:   0x1000061a8      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
| ========< 0x1000061ac      cbz   x0, 0x100006250
| ||:::|:   0x1000061b0      mov   x0, x19
| ||:::|:   0x1000061b4      bl    stub.objc_msgSend_description       ;  stub.objc_msgSend_description(void)
| ||:::|:   0x1000061b8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:::|:   0x1000061bc      mov   x20, x0
| ||:::|:   0x1000061c0      bl    sym.imp.objc_retainAutorelease
| ||:::|:   0x1000061c4      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| ||:::|:   0x1000061c8      str   x0, [sp]
| ||:::|:   0x1000061cc      adrp  x0, data.100008000                  ; 0x100008000
| ||:::|:   0x1000061d0      add   x0, x0, 0x86                        ; 0x100008086 ; "Current hardware:\n\n%s" ; const char *format
| ||:::|:   0x1000061d4      bl    sym.imp.printf                      ; int printf(const char *format)
| ||:::|:   0x1000061d8      mov   x0, x20                             ; void *instance
| ||:::|:   0x1000061dc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ========< 0x1000061e0      b     0x10000625c
| |`------> 0x1000061e4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | :::|:   0x1000061e8      ldr   x22, [x8, 0xbd0]                    ; [0x10000cbd0:4]=0x1c138 ; "8\xc1\U00000001"
| | :::|:   0x1000061ec      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | :::|:   0x1000061f0      ldr   x0, [x8, 0xbe8]                     ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
| | :::|:   0x1000061f4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | :::|:   0x1000061f8      ldr   x8, [x8, 0xc08]                     ; [0x10000cc08:4]=0x1c170 ; "p\xc1\U00000001"
| | :::|:   0x1000061fc      ldr   x2, [x8]                            ; [0x10001c170:4]=0
| | :::|:                                                              ; reloc.target.optarg
| | :::|:   0x100006200      bl    stub.objc_msgSend_stringWithUTF8String: ;  stub.objc_msgSend_stringWithUTF8String:(void)
| | :::|:   0x100006204      bl    sym.imp.objc_claimAutoreleasedReturnValue
| | :::|:   0x100006208      mov   x21, x0
| | :::|:   0x10000620c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | :::|:   0x100006210      add   x8, x8, 0x720                       ; 0x10000c720
| | :::|:                                                              ; reloc.__CFConstantStringClassReference.10000c720
| | :::|:   0x100006214      stp   x0, x8, [sp]
| | :::|:   0x100006218      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| | :::|:   0x10000621c      add   x2, x2, 0x700                       ; 0x10000c700
| | :::|:                                                              ; reloc.__CFConstantStringClassReference.10000c700
| | :::|:   0x100006220      mov   x0, x22
| | :::|:   0x100006224      bl    stub.objc_msgSend_stringWithFormat: ;  stub.objc_msgSend_stringWithFormat:(void)
| | :::|:   0x100006228      bl    sym.imp.objc_claimAutoreleasedReturnValue
| | :::|:   0x10000622c      mov   x22, x0
| | `=====< 0x100006230      b     0x100006038
| `----`--> 0x100006234      mov   x26, 0
|    :: :   0x100006238      mov   x23, 0
|    :: :   0x10000623c      mov   x22, 0
|    :: :   0x100006240      mov   x21, 0
|    :: :   0x100006244      mov   w19, 2
|    :: :   0x100006248      ldr   x20, [var_6b8h]                     ; [0x38:4]=-1 ; 56
|    ::,==< 0x10000624c      b     0x10000728c
| --------> 0x100006250      adrp  x0, data.100008000                  ; 0x100008000
|    ::|:   0x100006254      add   x0, x0, 0x4c2                       ; 0x1000084c2 ; "No supported hardware on this platform?" ; const char *s
|    ::|:   0x100006258      bl    sym.imp.puts                        ; int puts(const char *s)
|    ::|:   ; CODE XREF from entry0 @ 0x1000061e0
| --------> 0x10000625c      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
|    ::|:   0x100006260      ldr   x20, [x20, 0xc00]                   ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
|    ::|:   0x100006264      ldr   x0, [x20]                           ; [0x10001c168:4]=0
|    ::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
|    ::|:   0x100006268      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|    ::|:   0x10000626c      adrp  x0, data.100008000                  ; 0x100008000
|    ::|:   0x100006270      add   x0, x0, 0x50c                       ; const char *s
|    ::|:   0x100006274      bl    sym.imp.puts                        ; int puts(const char *s)
|    ::|:   0x100006278      ldr   x0, [x20]                           ; [0x10001c168:4]=0
|    ::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
|    ::|:   0x10000627c      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|    ::|:   0x100006280      mov   x0, x19                             ; void *instance
|    ::|:   0x100006284      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| --------> 0x100006288      ldrb  w1, [var_449h]                      ; [0x2a7:4]=-1 ; 679
|    ::|:   0x10000628c      mov   x0, x21                             ; void *instance
|    ::|:   0x100006290      mov   x2, x25                             ; int64_t arg3
|    ::|:   0x100006294      bl    sym.func.1000041cc
|    ::|:   0x100006298      bl    sym.imp.objc_claimAutoreleasedReturnValue
|    ::|:   0x10000629c      ldr   x20, [var_6b8h]                     ; [0x38:4]=-1 ; 56
|   ,=====< 0x1000062a0      cbz   x0, 0x100006df4
|   |::|:   0x1000062a4      mov   x19, x0
|   |::|:   0x1000062a8      str   x21, [var_6b0h]
|   |::|:   0x1000062ac      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
|  ,======< 0x1000062b0      tbz   w8, 0, 0x1000062d0
|  ||::|:   0x1000062b4      adrp  x0, data.100008000                  ; 0x100008000
|  ||::|:   0x1000062b8      add   x0, x0, 0x4ea                       ; 0x1000084ea ; "Identified the following matches:" ; const char *s
|  ||::|:   0x1000062bc      bl    sym.imp.puts                        ; int puts(const char *s)
|  ||::|:   0x1000062c0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x1000062c4      ldr   x8, [x8, 0xc00]                     ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
|  ||::|:   0x1000062c8      ldr   x0, [x8]                            ; [0x10001c168:4]=0
|  ||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
|  ||::|:   0x1000062cc      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  `------> 0x1000062d0      movi  v0.2d, 0000000000000000
|   |::|:   0x1000062d4      add   x8, var_550h
|   |::|:   0x1000062d8      stp   q0, q0, [x8, 0x60]
|   |::|:   0x1000062dc      stp   q0, q0, [x8, 0x40]
|   |::|:   0x1000062e0      mov   x0, x19                             ; void *instance
|   |::|:   0x1000062e4      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|   |::|:   0x1000062e8      mov   x20, x0
|   |::|:   0x1000062ec      add   x2, var_510h
|   |::|:   0x1000062f0      add   x3, var_2c0h
|   |::|:   0x1000062f4      mov   w4, 0x10
|   |::|:   0x1000062f8      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|   |::|:   0x1000062fc      str   x25, [var_688h]
|   |::|:   0x100006300      str   x20, [var_6d0h]
|  ,======< 0x100006304      cbz   x0, 0x100006e08
|  ||::|:   0x100006308      str   xzr, [var_690h]
|  ||::|:   0x10000630c      mov   x23, 0
|  ||::|:   0x100006310      mov   w28, -1
|  ||::|:   0x100006314      mov   w8, 0x7fffffff
|  ||::|:   0x100006318      str   w8, [var_67ch]
|  ||::|:   0x10000631c      ldr   x8, [var_500h]                      ; [0x1f0:4]=-1 ; 496
|  ||::|:   0x100006320      ldr   x8, [x8]
|  ||::|:   0x100006324      str   x8, [var_6a0h]
| .-------> 0x100006328      mov   x19, 0
| --------> 0x10000632c      str   x0, [var_660h]
| :||::|:   0x100006330      ldr   x8, [var_500h]                      ; [0x1f0:4]=-1 ; 496
| :||::|:   0x100006334      ldr   x8, [x8]
| :||::|:   0x100006338      ldr   x9, [var_6a0h]                      ; [0x50:4]=-1 ; 80
| :||::|:   0x10000633c      cmp   x8, x9
| ========< 0x100006340      b.eq  0x10000634c
| :||::|:   0x100006344      ldr   x0, [var_6d0h]                      ; [0x20:4]=-1 ; 32 ; void *instance
| :||::|:   0x100006348      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x10000634c      ldr   x8, [var_508h]                      ; [0x1e8:4]=-1 ; 488
| :||::|:   0x100006350      str   x19, [var_668h]
| :||::|:   0x100006354      ldr   x24, [x8, x19, lsl 3]
| :||::|:   0x100006358      mov   x0, x24
| :||::|:   0x10000635c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006360      add   x2, x2, 0x5c0                       ; 0x10000c5c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c5c0
| :||::|:   0x100006364      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006368      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000636c      str   x0, [var_5f0h]
| :||::|:   0x100006370      mov   x0, x24
| :||::|:   0x100006374      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006378      add   x2, x2, 0x180                       ; 0x10000c180
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c180
| :||::|:   0x10000637c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006380      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006384      mov   x20, x0
| :||::|:   0x100006388      mov   x0, x24
| :||::|:   0x10000638c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006390      add   x2, x2, 0x280                       ; 0x10000c280
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c280
| :||::|:   0x100006394      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006398      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000639c      mov   x26, x0
| :||::|:   0x1000063a0      mov   x0, x24
| :||::|:   0x1000063a4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000063a8      add   x2, x2, 0x2a0                       ; 0x10000c2a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c2a0
| :||::|:   0x1000063ac      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000063b0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000063b4      str   x0, [var_5f8h]
| :||::|:   0x1000063b8      mov   x0, x24
| :||::|:   0x1000063bc      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000063c0      add   x2, x2, 0x2c0                       ; 0x10000c2c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c2c0
| :||::|:   0x1000063c4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000063c8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000063cc      str   x0, [var_600h]
| :||::|:   0x1000063d0      mov   x0, x24
| :||::|:   0x1000063d4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000063d8      add   x2, x2, 0x4e0                       ; 0x10000c4e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
| :||::|:   0x1000063dc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000063e0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000063e4      str   x0, [var_608h]
| :||::|:   0x1000063e8      mov   x0, x24
| :||::|:   0x1000063ec      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000063f0      add   x2, x2, 0x3e0                       ; 0x10000c3e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| :||::|:   0x1000063f4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000063f8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000063fc      str   x0, [var_610h]
| :||::|:   0x100006400      mov   x0, x24
| :||::|:   0x100006404      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006408      add   x2, x2, 0x400                       ; 0x10000c400
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c400
| :||::|:   0x10000640c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006410      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006414      str   x0, [var_618h]
| :||::|:   0x100006418      mov   x0, x24
| :||::|:   0x10000641c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006420      add   x2, x2, 0x420                       ; 0x10000c420
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c420
| :||::|:   0x100006424      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006428      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000642c      str   x0, [var_620h]
| :||::|:   0x100006430      mov   x0, x24
| :||::|:   0x100006434      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006438      add   x2, x2, 0x460                       ; 0x10000c460
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c460
| :||::|:   0x10000643c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006440      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006444      str   x0, [var_628h]
| :||::|:   0x100006448      mov   x0, x24
| :||::|:   0x10000644c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006450      add   x2, x2, 0x4a0                       ; 0x10000c4a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
| :||::|:   0x100006454      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006458      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000645c      str   x0, [var_630h]
| :||::|:   0x100006460      mov   x0, x24
| :||::|:   0x100006464      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006468      add   x2, x2, 0x300                       ; 0x10000c300
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c300
| :||::|:   0x10000646c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006470      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006474      str   x0, [var_638h]
| :||::|:   0x100006478      mov   x0, x24
| :||::|:   0x10000647c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006480      add   x2, x2, 0x1e0                       ; 0x10000c1e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c1e0
| :||::|:   0x100006484      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006488      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000648c      str   x0, [var_640h]
| :||::|:   0x100006490      mov   x0, x24
| :||::|:   0x100006494      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006498      add   x2, x2, 0x220                       ; 0x10000c220
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c220
| :||::|:   0x10000649c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000064a0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000064a4      str   x0, [var_648h]
| :||::|:   0x1000064a8      mov   x0, x24
| :||::|:   0x1000064ac      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000064b0      add   x2, x2, 0x260                       ; 0x10000c260
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c260
| :||::|:   0x1000064b4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000064b8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000064bc      str   x0, [var_650h]
| :||::|:   0x1000064c0      mov   x0, x24
| :||::|:   0x1000064c4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000064c8      add   x2, x2, 0x2e0                       ; 0x10000c2e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c2e0
| :||::|:   0x1000064cc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000064d0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000064d4      mov   x19, x0
| :||::|:   0x1000064d8      mov   x0, x24
| :||::|:   0x1000064dc      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000064e0      add   x2, x2, 0x740                       ; 0x10000c740
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c740
| :||::|:   0x1000064e4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x1000064e8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x1000064ec      mov   x21, x0
| :||::|:   0x1000064f0      mov   x0, x24
| :||::|:   0x1000064f4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000064f8      add   x2, x2, 0x360                       ; 0x10000c360
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c360
| :||::|:   0x1000064fc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006500      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006504      mov   x22, x0
| :||::|:   0x100006508      mov   x0, x24
| :||::|:   0x10000650c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006510      add   x2, x2, 0x760                       ; 0x10000c760
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c760
| :||::|:   0x100006514      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006518      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000651c      mov   x27, x0
| :||::|:   0x100006520      mov   x0, x24
| :||::|:   0x100006524      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006528      add   x2, x2, 0x780                       ; 0x10000c780
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c780
| :||::|:   0x10000652c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006530      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006534      mov   x25, x0
| :||::|:   0x100006538      mov   x0, x24
| :||::|:   0x10000653c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006540      add   x2, x2, 0x7a0                       ; 0x10000c7a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c7a0
| :||::|:   0x100006544      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| :||::|:   0x100006548      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000654c      str   x0, [instance]
| :||::|:   0x100006550      mov   x0, x27
| :||::|:   0x100006554      bl    stub.objc_msgSend_unsignedIntValue  ;  stub.objc_msgSend_unsignedIntValue(void)
| :||::|:   0x100006558      ldr   w8, [var_67ch]                      ; [0x74:4]=-1 ; 116
| :||::|:   0x10000655c      cmp   w0, w8
| ========< 0x100006560      b.hs  0x100006570
| :||::|:   0x100006564      mov   x0, x27
| :||::|:   0x100006568      bl    stub.objc_msgSend_unsignedIntValue  ;  stub.objc_msgSend_unsignedIntValue(void)
| :||::|:   0x10000656c      str   w0, [var_67ch]
| --------> 0x100006570      str   x19, [var_658h]
| :||::|:   0x100006574      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
| :||::|:   0x100006578      ldr   x24, [var_5f0h]                     ; [0x100:4]=-1 ; 256
| :||::|:   0x10000657c      str   x25, [var_5e8h]
| ========< 0x100006580      tbz   w8, 0, 0x100006898
| :||::|:   0x100006584      mov   x0, x24
| :||::|:   0x100006588      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x10000658c      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x100006590      str   x0, [sp]
| :||::|:   0x100006594      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006598      add   x0, x0, 0xc2                        ; 0x1000080c2 ; "\tPERSONALITY_TYPE:               %s\n" ; const char *format
| :||::|:   0x10000659c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000065a0      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| :||::|:   0x1000065a4      ldr   x19, [x19, 0xc00]                   ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
| :||::|:   0x1000065a8      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000065ac      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000065b0      ldr   x0, [var_630h]                      ; [0xc0:4]=-1 ; 192
| :||::|:   0x1000065b4      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x1000065b8      str   x0, [sp]
| :||::|:   0x1000065bc      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000065c0      add   x0, x0, 0xe7                        ; 0x1000080e7 ; "\tCONFIG_PORT_ADDRESS:            %u\n" ; const char *format
| :||::|:   0x1000065c4      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000065c8      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000065cc      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000065d0      mov   x0, x20
| :||::|:   0x1000065d4      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x1000065d8      str   x0, [sp]
| :||::|:   0x1000065dc      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000065e0      add   x0, x0, 0x10c                       ; 0x10000810c ; "\tRID:                            %u\n" ; const char *format
| :||::|:   0x1000065e4      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000065e8      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000065ec      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000065f0      mov   x0, x26
| :||::|:   0x1000065f4      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x1000065f8      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x1000065fc      str   x0, [sp]
| :||::|:   0x100006600      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006604      add   x0, x0, 0x131                       ; 0x100008131 ; "\tCONFIG_MODEL_NAME:              %s\n" ; const char *format
| :||::|:   0x100006608      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x10000660c      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006610      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006614      ldr   x0, [var_5f8h]                      ; [0xf8:4]=-1 ; 248
| :||::|:   0x100006618      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x10000661c      str   x0, [sp]
| :||::|:   0x100006620      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006624      add   x0, x0, 0x156                       ; 0x100008156 ; "\tCONFIG_MODEL_ID:                %u\n" ; const char *format
| :||::|:   0x100006628      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x10000662c      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006630      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006634      ldr   x0, [var_600h]                      ; [0xf0:4]=-1 ; 240
| :||::|:   0x100006638      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x10000663c      str   x0, [sp]
| :||::|:   0x100006640      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006644      add   x0, x0, 0x17b                       ; 0x10000817b ; "\tCONFIG_MODEL_REVISION:          %u\n" ; const char *format
| :||::|:   0x100006648      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x10000664c      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006650      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006654      ldr   x0, [var_608h]                      ; [0xe8:4]=-1 ; 232
| :||::|:   0x100006658      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x10000665c      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x100006660      str   x0, [sp]
| :||::|:   0x100006664      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006668      add   x0, x0, 0x1a0                       ; 0x1000081a0 ; "\tCONFIG_PORT_UUID:               %s\n" ; const char *format
| :||::|:   0x10000666c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006670      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006674      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006678      ldr   x0, [var_610h]                      ; [0xe0:4]=-1 ; 224
| :||::|:   0x10000667c      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x100006680      str   x0, [sp]
| :||::|:   0x100006684      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006688      add   x0, x0, 0x1c5                       ; 0x1000081c5 ; "\tCONFIG_PORT_SILICON_VENDOR_ID:  %u\n" ; const char *format
| :||::|:   0x10000668c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006690      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006694      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006698      ldr   x0, [var_618h]                      ; [0xd8:4]=-1 ; 216
| :||::|:   0x10000669c      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x1000066a0      str   x0, [sp]
| :||::|:   0x1000066a4      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000066a8      add   x0, x0, 0x1ea                       ; 0x1000081ea ; "\tCONFIG_PORT_SILICON_DEVICE_ID:  %u\n" ; const char *format
| :||::|:   0x1000066ac      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000066b0      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000066b4      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000066b8      ldr   x0, [var_620h]                      ; [0xd0:4]=-1 ; 208
| :||::|:   0x1000066bc      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x1000066c0      str   x0, [sp]
| :||::|:   0x1000066c4      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000066c8      add   x0, x0, 0x20f                       ; 0x10000820f ; "\tCONFIG_PORT_SILICON_REVISION:   %u\n" ; const char *format
| :||::|:   0x1000066cc      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000066d0      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000066d4      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000066d8      ldr   x0, [var_628h]                      ; [0xc8:4]=-1 ; 200
| :||::|:   0x1000066dc      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x1000066e0      str   x0, [sp]
| :||::|:   0x1000066e4      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000066e8      add   x0, x0, 0x234                       ; 0x100008234 ; "\tCONFIG_PORT_OTP_REVISION:       %u\n" ; const char *format
| :||::|:   0x1000066ec      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000066f0      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000066f4      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000066f8      ldr   x0, [var_638h]                      ; [0xb8:4]=-1 ; 184
| :||::|:   0x1000066fc      bl    stub.objc_msgSend_unsignedLongLongValue ;  stub.objc_msgSend_unsignedLongLongValue(void)
| :||::|:   0x100006700      str   x0, [sp]
| :||::|:   0x100006704      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006708      add   x0, x0, 0x259                       ; 0x100008259 ; "\tCONFIG_RIDGE_UID:               0x%llX\n" ; const char *format
| :||::|:   0x10000670c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006710      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006714      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006718      ldr   x0, [var_640h]                      ; [0xb0:4]=-1 ; 176
| :||::|:   0x10000671c      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x100006720      str   x0, [sp]
| :||::|:   0x100006724      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006728      add   x0, x0, 0x282                       ; 0x100008282 ; "\tCONFIG_RIDGE_SILICON_VENDOR_ID: %u\n" ; const char *format
| :||::|:   0x10000672c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006730      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006734      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006738      ldr   x0, [var_648h]                      ; [0xa8:4]=-1 ; 168
| :||::|:   0x10000673c      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x100006740      str   x0, [sp]
| :||::|:   0x100006744      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006748      add   x0, x0, 0x2a7                       ; 0x1000082a7 ; "\tCONFIG_RIDGE_SILICON_DEVICE_ID: %u\n" ; const char *format
| :||::|:   0x10000674c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006750      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006754      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006758      ldr   x0, [var_650h]                      ; [0xa0:4]=-1 ; 160
| :||::|:   0x10000675c      bl    stub.objc_msgSend_intValue          ;  stub.objc_msgSend_intValue(void)
| :||::|:   0x100006760      str   x0, [sp]
| :||::|:   0x100006764      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006768      add   x0, x0, 0x2cc                       ; 0x1000082cc ; "\tCONFIG_RIDGE_SILICON_REVISION:  %u\n" ; const char *format
| :||::|:   0x10000676c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006770      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006774      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006778      ldr   x0, [var_658h]                      ; [0x98:4]=-1 ; 152
| :||::|:   0x10000677c      bl    stub.objc_msgSend_unsignedIntValue  ;  stub.objc_msgSend_unsignedIntValue(void)
| :||::|:   0x100006780      str   x0, [sp]
| :||::|:   0x100006784      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006788      add   x0, x0, 0x2f1                       ; 0x1000082f1 ; "\tCONFIG_RIDGE_FIRMWARE_MODE:     %u\n" ; const char *format
| :||::|:   0x10000678c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006790      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006794      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006798      mov   x0, x21
| :||::|:   0x10000679c      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x1000067a0      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x1000067a4      str   x0, [sp]
| :||::|:   0x1000067a8      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000067ac      add   x0, x0, 0x316                       ; 0x100008316 ; "\tCONFIG_FIRMWARE_NAME:           %s\n" ; const char *format
| :||::|:   0x1000067b0      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000067b4      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000067b8      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000067bc      mov   x0, x22
| :||::|:   0x1000067c0      bl    stub.objc_msgSend_floatValue        ;  stub.objc_msgSend_floatValue(void)
| :||::|:   0x1000067c4      fcvt  d0, s0
| :||::|:   0x1000067c8      str   d0, [sp]
| :||::|:   0x1000067cc      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000067d0      add   x0, x0, 0x33b                       ; 0x10000833b ; "\tCONFIG_VERSION:                 %1.02f\n" ; const char *format
| :||::|:   0x1000067d4      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000067d8      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000067dc      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x1000067e0      mov   x0, x27
| :||::|:   0x1000067e4      bl    stub.objc_msgSend_unsignedIntValue  ;  stub.objc_msgSend_unsignedIntValue(void)
| :||::|:   0x1000067e8      str   x0, [sp]
| :||::|:   0x1000067ec      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x1000067f0      add   x0, x0, 0x364                       ; 0x100008364 ; "\tCONFIG_PRIORITY:                %u\n" ; const char *format
| :||::|:   0x1000067f4      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x1000067f8      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x1000067fc      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006800      mov   x0, x25
| :||::|:   0x100006804      bl    stub.objc_msgSend_description       ;  stub.objc_msgSend_description(void)
| :||::|:   0x100006808      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000680c      mov   x25, x20
| :||::|:   0x100006810      mov   x20, x23
| :||::|:   0x100006814      mov   x23, x0
| :||::|:   0x100006818      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x10000681c      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x100006820      str   x0, [sp]
| :||::|:   0x100006824      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006828      add   x0, x0, 0x389                       ; 0x100008389 ; "\tCONFIG_NVRAM_TO_SET:\n%s\n" ; const char *format
| :||::|:   0x10000682c      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006830      mov   x0, x23                             ; void *instance
| :||::|:   0x100006834      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006838      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x10000683c      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006840      ldr   x0, [instance]                      ; [0x110:4]=-1 ; 272
| :||::|:   0x100006844      bl    stub.objc_msgSend_description       ;  stub.objc_msgSend_description(void)
| :||::|:   0x100006848      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x10000684c      mov   x23, x0
| :||::|:   0x100006850      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x100006854      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x100006858      str   x0, [sp]
| :||::|:   0x10000685c      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006860      add   x0, x0, 0x3a3                       ; 0x1000083a3 ; "\tCONFIG_NVRAM_TO_CLEAR:\n%s\n" ; const char *format
| :||::|:   0x100006864      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006868      mov   x0, x23                             ; void *instance
| :||::|:   0x10000686c      mov   x23, x20
| :||::|:   0x100006870      mov   x20, x25
| :||::|:   0x100006874      ldr   x25, [var_5e8h]                     ; [0x108:4]=-1 ; 264
| :||::|:   0x100006878      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x10000687c      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006880      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| :||::|:   0x100006884      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006888      add   x0, x0, 0x50c                       ; const char *s
| :||::|:   0x10000688c      bl    sym.imp.puts                        ; int puts(const char *s)
| :||::|:   0x100006890      ldr   x0, [x19]                           ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006894      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| --------> 0x100006898      mov   x0, x24
| :||::|:   0x10000689c      mov   x2, x23
| :||::|:   0x1000068a0      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x1000068a4      cbz   x0, 0x1000069e0
| :||::|:   0x1000068a8      mov   x0, x24                             ; void *instance
| :||::|:   0x1000068ac      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| :||::|:   0x1000068b0      mov   x25, x0
| :||::|:   0x1000068b4      mov   x0, x23                             ; void *instance
| :||::|:   0x1000068b8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x1000068bc      ldr   x28, [var_678h]                     ; [0x78:4]=-1 ; 120
| :||::|:   0x1000068c0      mov   x0, x28
| :||::|:   0x1000068c4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000068c8      add   x2, x2, 0x7c0                       ; 0x10000c7c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c7c0
| :||::|:   0x1000068cc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x1000068d0      mov   x0, x28
| :||::|:   0x1000068d4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000068d8      add   x2, x2, 0x7e0                       ; 0x10000c7e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c7e0
| :||::|:   0x1000068dc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x1000068e0      mov   x0, x28
| :||::|:   0x1000068e4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000068e8      add   x2, x2, 0x800                       ; 0x10000c800
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c800
| :||::|:   0x1000068ec      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x1000068f0      mov   x0, x28
| :||::|:   0x1000068f4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000068f8      add   x2, x2, 0x820                       ; 0x10000c820
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c820
| :||::|:   0x1000068fc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006900      ldr   x0, [var_688h]                      ; [0x68:4]=-1 ; 104
| :||::|:   0x100006904      bl    stub.objc_msgSend_mutableCopy       ;  stub.objc_msgSend_mutableCopy(void)
| :||::|:   0x100006908      mov   x23, x0
| :||::|:   0x10000690c      ldr   x0, [var_690h]                      ; [0x60:4]=-1 ; 96 ; void *instance
| :||::|:   0x100006910      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006914      mov   x0, x25
| :||::|:   0x100006918      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x10000691c      add   x2, x2, 0x5a0                       ; 0x10000c5a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c5a0
| :||::|:   0x100006920      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006924      cbz   x0, 0x100006970
| :||::|:   0x100006928      mov   x0, x25
| :||::|:   0x10000692c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006930      add   x2, x2, 0x5e0                       ; 0x10000c5e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c5e0
| :||::|:   0x100006934      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006938      cbz   x0, 0x100006970
| :||::|:   0x10000693c      mov   x0, x25
| :||::|:   0x100006940      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006944      add   x2, x2, 0x620                       ; 0x10000c620
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c620
| :||::|:   0x100006948      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x10000694c      cbz   x0, 0x100006964
| :||::|:   0x100006950      mov   x0, x25
| :||::|:   0x100006954      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006958      add   x2, x2, 0x600                       ; 0x10000c600
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c600
| :||::|:   0x10000695c      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006960      cbnz  x0, 0x100006980
| --------> 0x100006964      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006968      add   x2, x2, 0x860                       ; 0x10000c860
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c860
| ========< 0x10000696c      b     0x100006978
| --------> 0x100006970      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006974      add   x2, x2, 0x840                       ; 0x10000c840
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c840
| :||::|:   ; CODE XREF from entry0 @ 0x10000696c
| --------> 0x100006978      mov   x0, x23
| :||::|:   0x10000697c      bl    stub.objc_msgSend_appendString:     ;  stub.objc_msgSend_appendString:(void)
| --------> 0x100006980      mov   x0, x28
| :||::|:   0x100006984      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006988      add   x2, x2, 0x880                       ; 0x10000c880
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c880
| :||::|:   0x10000698c      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006990      mov   x0, x28
| :||::|:   0x100006994      mov   x2, x23
| :||::|:   0x100006998      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x10000699c      ldr   x19, [var_6c8h]                     ; [0x28:4]=-1 ; 40
| :||::|:   0x1000069a0      mov   x0, x19
| :||::|:   0x1000069a4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000069a8      add   x2, x2, 0x8a0                       ; 0x10000c8a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c8a0
| :||::|:   0x1000069ac      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x1000069b0      mov   x0, x19
| :||::|:   0x1000069b4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000069b8      add   x2, x2, 0x8c0                       ; 0x10000c8c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c8c0
| :||::|:   0x1000069bc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x1000069c0      mov   x0, x19
| :||::|:   0x1000069c4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x1000069c8      add   x2, x2, 0x8e0                       ; 0x10000c8e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c8e0
| :||::|:   0x1000069cc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x1000069d0      mov   w28, 0
| :||::|:   0x1000069d4      str   x23, [var_690h]
| :||::|:   0x1000069d8      mov   x23, x25
| :||::|:   0x1000069dc      ldr   x25, [var_5e8h]                     ; [0x108:4]=-1 ; 264
| --------> 0x1000069e0      ldr   x19, [instance]                     ; [0x110:4]=-1 ; 272
| :||::|:   0x1000069e4      str   x27, [var_670h]
| ========< 0x1000069e8      cbz   x25, 0x1000069f8
| :||::|:   0x1000069ec      ldr   x0, [var_6c0h]                      ; [0x30:4]=-1 ; 48
| :||::|:   0x1000069f0      mov   x2, x25
| :||::|:   0x1000069f4      bl    stub.objc_msgSend_addEntriesFromDictionary: ;  stub.objc_msgSend_addEntriesFromDictionary:(void)
| --------> 0x1000069f8      mov   x27, x22
| ========< 0x1000069fc      cbz   x19, 0x100006a0c
| :||::|:   0x100006a00      ldr   x0, [var_6b8h]                      ; [0x38:4]=-1 ; 56
| :||::|:   0x100006a04      mov   x2, x19
| :||::|:   0x100006a08      bl    stub.objc_msgSend_addObjectsFromArray: ;  stub.objc_msgSend_addObjectsFromArray:(void)
| --------> 0x100006a0c      mov   x22, x21
| :||::|:   0x100006a10      mov   x0, x24
| :||::|:   0x100006a14      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006a18      add   x2, x2, 0x5a0                       ; 0x10000c5a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c5a0
| :||::|:   0x100006a1c      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006a20      cbz   x0, 0x100006a9c
| :||::|:   0x100006a24      mov   x0, x24
| :||::|:   0x100006a28      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006a2c      add   x2, x2, 0x5e0                       ; 0x10000c5e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c5e0
| :||::|:   0x100006a30      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006a34      cbz   x0, 0x100006a9c
| :||::|:   0x100006a38      mov   x0, x24
| :||::|:   0x100006a3c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006a40      add   x2, x2, 0x600                       ; 0x10000c600
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c600
| :||::|:   0x100006a44      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006a48      cbz   x0, 0x100006bf4
| :||::|:   0x100006a4c      mov   x0, x24
| :||::|:   0x100006a50      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006a54      add   x2, x2, 0x620                       ; 0x10000c620
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c620
| :||::|:   0x100006a58      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ========< 0x100006a5c      cbz   x0, 0x100006bf4
| :||::|:   0x100006a60      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
| :||::|:   0x100006a64      ldr   x21, [var_658h]                     ; [0x98:4]=-1 ; 152
| ========< 0x100006a68      tbz   w8, 0, 0x100006d00
| :||::|:   0x100006a6c      mov   x0, x24
| :||::|:   0x100006a70      bl    sym.imp.objc_retainAutorelease
| :||::|:   0x100006a74      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| :||::|:   0x100006a78      str   x0, [sp]
| :||::|:   0x100006a7c      adrp  x0, data.100008000                  ; 0x100008000
| :||::|:   0x100006a80      add   x0, x0, 0x45a                       ; 0x10000845a ; "\t*** No supported platform type? (was using %s)***\n" ; const char *format
| :||::|:   0x100006a84      bl    sym.imp.printf                      ; int printf(const char *format)
| :||::|:   0x100006a88      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006a8c      ldr   x8, [x8, 0xc00]                     ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
| :||::|:   0x100006a90      ldr   x0, [x8]                            ; [0x10001c168:4]=0
| :||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
| :||::|:   0x100006a94      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| ========< 0x100006a98      b     0x100006d00
| --------> 0x100006a9c      ldr   x19, [var_6a8h]                     ; [0x48:4]=-1 ; 72
| :||::|:   0x100006aa0      mov   x0, x19
| :||::|:   0x100006aa4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006aa8      add   x2, x2, 0x900                       ; 0x10000c900
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c900
| :||::|:   0x100006aac      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006ab0      mov   x0, x19
| :||::|:   0x100006ab4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006ab8      add   x2, x2, 0x920                       ; 0x10000c920
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c920
| :||::|:   0x100006abc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006ac0      mov   x0, x19
| :||::|:   0x100006ac4      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006ac8      add   x2, x2, 0x940                       ; 0x10000c940
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c940
| :||::|:   0x100006acc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006ad0      adrp  x25, section.7.__DATA_CONST.__const ; 0x10000c000
| :||::|:   0x100006ad4      mov   x24, x26
| :||::|:   0x100006ad8      mov   x26, x23
| :||::|:   0x100006adc      ldr   x23, [x25, 0xbe8]                   ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
| :||::|:   0x100006ae0      mov   x0, x20
| :||::|:   0x100006ae4      bl    stub.objc_msgSend_unsignedIntValue  ;  stub.objc_msgSend_unsignedIntValue(void)
| :||::|:   0x100006ae8      str   x0, [sp]
| :||::|:   0x100006aec      mov   x0, x23
| :||::|:   0x100006af0      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006af4      add   x2, x2, 0x960                       ; 0x10000c960
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c960
| :||::|:   0x100006af8      bl    stub.objc_msgSend_stringWithFormat: ;  stub.objc_msgSend_stringWithFormat:(void)
| :||::|:   0x100006afc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006b00      mov   x23, x0
| :||::|:   0x100006b04      mov   x0, x19
| :||::|:   0x100006b08      mov   x2, x23
| :||::|:   0x100006b0c      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006b10      mov   x0, x23                             ; void *instance
| :||::|:   0x100006b14      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006b18      mov   x0, x19
| :||::|:   0x100006b1c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006b20      add   x2, x2, 0x6c0                       ; 0x10000c6c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c6c0
| :||::|:   0x100006b24      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006b28      ldr   x21, [var_658h]                     ; [0x98:4]=-1 ; 152
| :||::|:   0x100006b2c      mov   x0, x21
| :||::|:   0x100006b30      bl    stub.objc_msgSend_unsignedIntValue  ;  stub.objc_msgSend_unsignedIntValue(void)
| :||::|:   0x100006b34      cmp   w0, 0
| :||::|:   0x100006b38      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006b3c      add   x8, x8, 0x9a0                       ; 0x10000c9a0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c9a0
| :||::|:   0x100006b40      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006b44      add   x9, x9, 0x980                       ; 0x10000c980
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c980
| :||::|:   0x100006b48      csel  x2, x9, x8, eq
| :||::|:   0x100006b4c      mov   x0, x19
| :||::|:   0x100006b50      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006b54      ldr   x0, [x25, 0xbe8]                    ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
| :||::|:   0x100006b58      str   x28, [sp]
| :||::|:   0x100006b5c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006b60      add   x2, x2, 0x9c0                       ; 0x10000c9c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c9c0
| :||::|:   0x100006b64      bl    stub.objc_msgSend_stringWithFormat: ;  stub.objc_msgSend_stringWithFormat:(void)
| :||::|:   0x100006b68      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006b6c      mov   x23, x0
| :||::|:   0x100006b70      mov   x0, x19
| :||::|:   0x100006b74      mov   x2, x23
| :||::|:   0x100006b78      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006b7c      mov   x0, x23                             ; void *instance
| :||::|:   0x100006b80      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006b84      ldr   x0, [var_688h]                      ; [0x68:4]=-1 ; 104
| :||::|:   0x100006b88      ldr   x2, [var_6b0h]                      ; [0x40:4]=-1 ; 64
| :||::|:   0x100006b8c      bl    stub.objc_msgSend_stringByAppendingPathComponent: ;  stub.objc_msgSend_stringByAppendingPathComponent:(void)
| :||::|:   0x100006b90      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006b94      mov   x23, x0
| :||::|:   0x100006b98      ldr   x19, [var_678h]                     ; [0x78:4]=-1 ; 120
| :||::|:   0x100006b9c      mov   x0, x19
| :||::|:   0x100006ba0      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006ba4      add   x2, x2, 0x9e0                       ; 0x10000c9e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c9e0
| :||::|:   0x100006ba8      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006bac      mov   x0, x23
| :||::|:   0x100006bb0      mov   x2, x22
| :||::|:   0x100006bb4      bl    stub.objc_msgSend_stringByAppendingPathComponent: ;  stub.objc_msgSend_stringByAppendingPathComponent:(void)
| :||::|:   0x100006bb8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006bbc      mov   x25, x0
| :||::|:   0x100006bc0      mov   x0, x19
| :||::|:   0x100006bc4      ldr   x19, [instance]                     ; [0x110:4]=-1 ; 272
| :||::|:   0x100006bc8      mov   x2, x25
| :||::|:   0x100006bcc      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006bd0      mov   x0, x25                             ; void *instance
| :||::|:   0x100006bd4      ldr   x25, [var_5e8h]                     ; [0x108:4]=-1 ; 264
| :||::|:   0x100006bd8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006bdc      mov   x0, x23                             ; void *instance
| :||::|:   0x100006be0      mov   x23, x26
| :||::|:   0x100006be4      mov   x26, x24
| :||::|:   0x100006be8      ldr   x24, [var_5f0h]                     ; [0x100:4]=-1 ; 256
| :||::|:   0x100006bec      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ========< 0x100006bf0      b     0x100006d00
| --------> 0x100006bf4      ldr   x19, [var_6a8h]                     ; [0x48:4]=-1 ; 72
| :||::|:   0x100006bf8      mov   x0, x19
| :||::|:   0x100006bfc      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c00      add   x2, x2, 0x900                       ; 0x10000c900
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c900
| :||::|:   0x100006c04      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006c08      mov   x0, x19
| :||::|:   0x100006c0c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c10      add   x2, x2, 0xa00                       ; 0x10000ca00
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000ca00
| :||::|:   0x100006c14      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006c18      mov   x0, x19
| :||::|:   0x100006c1c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c20      add   x2, x2, 0x920                       ; 0x10000c920
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c920
| :||::|:   0x100006c24      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006c28      mov   x0, x19
| :||::|:   0x100006c2c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c30      add   x2, x2, 0xa20                       ; 0x10000ca20
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000ca20
| :||::|:   0x100006c34      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006c38      mov   x0, x19
| :||::|:   0x100006c3c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c40      add   x2, x2, 0xa40                       ; 0x10000ca40
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000ca40
| :||::|:   0x100006c44      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006c48      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c4c      ldr   x0, [x8, 0xbe8]                     ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
| :||::|:   0x100006c50      mov   x8, x28
| :||::|:   0x100006c54      str   x8, [sp]
| :||::|:   0x100006c58      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006c5c      add   x2, x2, 0x9c0                       ; 0x10000c9c0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c9c0
| :||::|:   0x100006c60      bl    stub.objc_msgSend_stringWithFormat: ;  stub.objc_msgSend_stringWithFormat:(void)
| :||::|:   0x100006c64      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006c68      mov   x24, x26
| :||::|:   0x100006c6c      mov   x26, x20
| :||::|:   0x100006c70      mov   x20, x23
| :||::|:   0x100006c74      mov   x23, x0
| :||::|:   0x100006c78      mov   x0, x19
| :||::|:   0x100006c7c      mov   x2, x23
| :||::|:   0x100006c80      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006c84      mov   x0, x23                             ; void *instance
| :||::|:   0x100006c88      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006c8c      ldr   x0, [var_688h]                      ; [0x68:4]=-1 ; 104
| :||::|:   0x100006c90      ldr   x2, [var_6b0h]                      ; [0x40:4]=-1 ; 64
| :||::|:   0x100006c94      bl    stub.objc_msgSend_stringByAppendingPathComponent: ;  stub.objc_msgSend_stringByAppendingPathComponent:(void)
| :||::|:   0x100006c98      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006c9c      mov   x23, x0
| :||::|:   0x100006ca0      ldr   x19, [var_678h]                     ; [0x78:4]=-1 ; 120
| :||::|:   0x100006ca4      mov   x0, x19
| :||::|:   0x100006ca8      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| :||::|:   0x100006cac      add   x2, x2, 0x9e0                       ; 0x10000c9e0
| :||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c9e0
| :||::|:   0x100006cb0      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006cb4      mov   x0, x23
| :||::|:   0x100006cb8      mov   x2, x22
| :||::|:   0x100006cbc      bl    stub.objc_msgSend_stringByAppendingPathComponent: ;  stub.objc_msgSend_stringByAppendingPathComponent:(void)
| :||::|:   0x100006cc0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| :||::|:   0x100006cc4      mov   x25, x0
| :||::|:   0x100006cc8      mov   x0, x19
| :||::|:   0x100006ccc      ldr   x19, [instance]                     ; [0x110:4]=-1 ; 272
| :||::|:   0x100006cd0      mov   x2, x25
| :||::|:   0x100006cd4      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006cd8      mov   x0, x25                             ; void *instance
| :||::|:   0x100006cdc      ldr   x25, [var_5e8h]                     ; [0x108:4]=-1 ; 264
| :||::|:   0x100006ce0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006ce4      mov   x0, x23                             ; void *instance
| :||::|:   0x100006ce8      mov   x23, x20
| :||::|:   0x100006cec      mov   x20, x26
| :||::|:   0x100006cf0      mov   x26, x24
| :||::|:   0x100006cf4      ldr   x24, [var_5f0h]                     ; [0x100:4]=-1 ; 256
| :||::|:   0x100006cf8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006cfc      ldr   x21, [var_658h]                     ; [0x98:4]=-1 ; 152
| :||::|:   ; CODE XREFS from entry0 @ 0x100006a98, 0x100006bf0
| --------> 0x100006d00      add   w28, w28, 1                         ; 0x100000000
| :||::|:                                                              ; sym.__mh_execute_header
| :||::|:   0x100006d04      mov   x0, x19                             ; void *instance
| :||::|:   0x100006d08      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d0c      mov   x0, x25                             ; void *instance
| :||::|:   0x100006d10      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d14      ldr   x0, [var_670h]                      ; [0x80:4]=-1 ; 128 ; void *instance
| :||::|:   0x100006d18      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d1c      mov   x0, x27                             ; void *instance
| :||::|:   0x100006d20      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d24      mov   x0, x22                             ; void *instance
| :||::|:   0x100006d28      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d2c      mov   x0, x21                             ; void *instance
| :||::|:   0x100006d30      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d34      ldr   x0, [var_650h]                      ; [0xa0:4]=-1 ; 160 ; void *instance
| :||::|:   0x100006d38      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d3c      ldr   x0, [var_648h]                      ; [0xa8:4]=-1 ; 168 ; void *instance
| :||::|:   0x100006d40      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d44      ldr   x0, [var_640h]                      ; [0xb0:4]=-1 ; 176 ; void *instance
| :||::|:   0x100006d48      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d4c      ldr   x0, [var_638h]                      ; [0xb8:4]=-1 ; 184 ; void *instance
| :||::|:   0x100006d50      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d54      ldr   x0, [var_630h]                      ; [0xc0:4]=-1 ; 192 ; void *instance
| :||::|:   0x100006d58      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d5c      ldr   x0, [var_628h]                      ; [0xc8:4]=-1 ; 200 ; void *instance
| :||::|:   0x100006d60      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d64      ldr   x0, [var_620h]                      ; [0xd0:4]=-1 ; 208 ; void *instance
| :||::|:   0x100006d68      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d6c      ldr   x0, [var_618h]                      ; [0xd8:4]=-1 ; 216 ; void *instance
| :||::|:   0x100006d70      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d74      ldr   x0, [var_610h]                      ; [0xe0:4]=-1 ; 224 ; void *instance
| :||::|:   0x100006d78      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d7c      ldr   x0, [var_608h]                      ; [0xe8:4]=-1 ; 232 ; void *instance
| :||::|:   0x100006d80      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d84      ldr   x0, [var_600h]                      ; [0xf0:4]=-1 ; 240 ; void *instance
| :||::|:   0x100006d88      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d8c      ldr   x0, [var_5f8h]                      ; [0xf8:4]=-1 ; 248 ; void *instance
| :||::|:   0x100006d90      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d94      mov   x0, x26                             ; void *instance
| :||::|:   0x100006d98      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006d9c      mov   x0, x20                             ; void *instance
| :||::|:   0x100006da0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006da4      mov   x0, x24                             ; void *instance
| :||::|:   0x100006da8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| :||::|:   0x100006dac      ldp   x19, x0, [var_668h]
| :||::|:   0x100006db0      add   x19, x19, 1
| :||::|:   0x100006db4      subs  x0, x0, 1
| ========< 0x100006db8      b.ne  0x10000632c
| :||::|:   0x100006dbc      add   x2, var_510h
| :||::|:   0x100006dc0      add   x3, var_2c0h
| :||::|:   0x100006dc4      ldr   x20, [var_6d0h]                     ; [0x20:4]=-1 ; 32
| :||::|:   0x100006dc8      mov   x0, x20
| :||::|:   0x100006dcc      mov   w4, 0x10
| :||::|:   0x100006dd0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| `=======< 0x100006dd4      cbnz  x0, 0x100006328
|  ||::|:   0x100006dd8      str   x23, [instance]
|  ||::|:   0x100006ddc      ldr   w8, [var_67ch]                      ; [0x74:4]=-1 ; 116
|  ||::|:   0x100006de0      mov   w19, w8
|  ||::|:   0x100006de4      ldr   x27, [var_678h]                     ; [0x78:4]=-1 ; 120
|  ||::|:   0x100006de8      ldr   x28, [var_6c0h]                     ; [0x30:4]=-1 ; 48
|  ||::|:   0x100006dec      ldr   x24, [var_690h]                     ; [0x60:4]=-1 ; 96
| ,=======< 0x100006df0      b     0x100006e14
| ||`-----> 0x100006df4      mov   x26, 0
| || ::|:   0x100006df8      mov   x23, 0
| || ::|:   0x100006dfc      mov   x22, 0
| || ::|:   0x100006e00      mov   w19, 0xd
| ||,=====< 0x100006e04      b     0x10000728c
| |`------> 0x100006e08      mov   x24, 0
| | |::|:   0x100006e0c      str   xzr, [instance]
| | |::|:   0x100006e10      mov   w19, 0x7fffffff
| | |::|:   ; CODE XREF from entry0 @ 0x100006df0
| `-------> 0x100006e14      mov   x0, x20                             ; void *instance
|   |::|:   0x100006e18      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |::|:   0x100006e1c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|   |::|:   0x100006e20      add   x2, x2, 0xa60                       ; 0x10000ca60
|   |::|:                                                              ; reloc.__CFConstantStringClassReference.10000ca60
|   |::|:   0x100006e24      ldr   x0, [var_6a8h]                      ; [0x48:4]=-1 ; 72
|   |::|:   0x100006e28      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
|   |::|:   0x100006e2c      add   x8, var_550h
|   |::|:   0x100006e30      movi  v0.2d, 0000000000000000
|   |::|:   0x100006e34      stp   q0, q0, [x8, 0x20]
|   |::|:   0x100006e38      stp   q0, q0, [x8]
|   |::|:   0x100006e3c      ldr   x0, [var_6c8h]                      ; [0x28:4]=-1 ; 40 ; void *instance
|   |::|:   0x100006e40      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|   |::|:   0x100006e44      mov   x20, x0
|   |::|:   0x100006e48      add   x2, var_550h
|   |::|:   0x100006e4c      add   x3, var_340h
|   |::|:   0x100006e50      mov   w4, 0x10
|   |::|:   0x100006e54      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|  ,======< 0x100006e58      cbz   x0, 0x100006ebc
|  ||::|:   0x100006e5c      mov   x21, x0
|  ||::|:   0x100006e60      ldr   x8, [var_540h]                      ; [0x1b0:4]=-1 ; 432
|  ||::|:   0x100006e64      ldr   x22, [x8]
| .-------> 0x100006e68      mov   x23, 0
| --------> 0x100006e6c      ldr   x8, [var_540h]                      ; [0x1b0:4]=-1 ; 432
| :||::|:   0x100006e70      ldr   x8, [x8]
| :||::|:   0x100006e74      cmp   x8, x22
| ========< 0x100006e78      b.eq  0x100006e84
| :||::|:   0x100006e7c      mov   x0, x20                             ; void *instance
| :||::|:   0x100006e80      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100006e84      ldr   x8, [var_548h]                      ; [0x1a8:4]=-1 ; 424
| :||::|:   0x100006e88      ldr   x2, [x8, x23, lsl 3]
| :||::|:   0x100006e8c      mov   x0, x27
| :||::|:   0x100006e90      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| :||::|:   0x100006e94      add   x23, x23, 1
| :||::|:   0x100006e98      subs  x21, x21, 1
| ========< 0x100006e9c      b.ne  0x100006e6c
| :||::|:   0x100006ea0      add   x2, var_550h
| :||::|:   0x100006ea4      add   x3, var_340h
| :||::|:   0x100006ea8      mov   x0, x20
| :||::|:   0x100006eac      mov   w4, 0x10
| :||::|:   0x100006eb0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| :||::|:   0x100006eb4      mov   x21, x0
| `=======< 0x100006eb8      cbnz  x0, 0x100006e68
|  `------> 0x100006ebc      str   x24, [var_690h]
|   |::|:   0x100006ec0      mov   x0, x20                             ; void *instance
|   |::|:   0x100006ec4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |::|:   0x100006ec8      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|   |::|:   0x100006ecc      ldr   x0, [x8, 0xbd0]                     ; [0x10000cbd0:4]=0x1c138 ; "8\xc1\U00000001"
|   |::|:   0x100006ed0      bl    stub.objc_msgSend_string            ;  stub.objc_msgSend_string(void)
|   |::|:   0x100006ed4      bl    sym.imp.objc_claimAutoreleasedReturnValue
|   |::|:   0x100006ed8      mov   x20, x0
|   |::|:   0x100006edc      movi  v0.2d, 0000000000000000
|   |::|:   0x100006ee0      stp   q0, q0, [var_590h]
|   |::|:   0x100006ee4      stp   q0, q0, [var_580h + 0x10]
|   |::|:   0x100006ee8      ldr   x0, [var_6a8h]                      ; [0x48:4]=-1 ; 72 ; void *instance
|   |::|:   0x100006eec      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|   |::|:   0x100006ef0      mov   x21, x0
|   |::|:   0x100006ef4      add   x2, var_590h
|   |::|:   0x100006ef8      add   x3, var_3c0h
|   |::|:   0x100006efc      mov   w4, 0x10
|   |::|:   0x100006f00      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|  ,======< 0x100006f04      cbz   x0, 0x100006f8c
|  ||::|:   0x100006f08      mov   x22, x0
|  ||::|:   0x100006f0c      ldr   x8, [var_580h]                      ; [0x170:4]=-1 ; 368
|  ||::|:   0x100006f10      ldr   x25, [x8]
|  ||::|:   0x100006f14      adrp  x23, section.7.__DATA_CONST.__const ; 0x10000c000
|  ||::|:   0x100006f18      add   x23, x23, 0x660                     ; 0x10000c660
|  ||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c660
| .-------> 0x100006f1c      mov   x26, 0
| --------> 0x100006f20      ldr   x8, [var_580h]                      ; [0x170:4]=-1 ; 368
| :||::|:   0x100006f24      ldr   x8, [x8]
| :||::|:   0x100006f28      cmp   x8, x25
| ========< 0x100006f2c      b.eq  0x100006f38
| :||::|:   0x100006f30      mov   x0, x21                             ; void *instance
| :||::|:   0x100006f34      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100006f38      ldr   x8, [var_588h]                      ; [0x168:4]=-1 ; 360
| :||::|:   0x100006f3c      ldr   x24, [x8, x26, lsl 3]
| :||::|:   0x100006f40      mov   x0, x20
| :||::|:   0x100006f44      bl    stub.objc_msgSend_length            ;  stub.objc_msgSend_length(void)
| ========< 0x100006f48      cbz   x0, 0x100006f58
| :||::|:   0x100006f4c      mov   x0, x20
| :||::|:   0x100006f50      mov   x2, x23
| :||::|:   0x100006f54      bl    stub.objc_msgSend_appendString:     ;  stub.objc_msgSend_appendString:(void)
| --------> 0x100006f58      mov   x0, x20
| :||::|:   0x100006f5c      mov   x2, x24
| :||::|:   0x100006f60      bl    stub.objc_msgSend_appendString:     ;  stub.objc_msgSend_appendString:(void)
| :||::|:   0x100006f64      add   x26, x26, 1
| :||::|:   0x100006f68      subs  x22, x22, 1
| ========< 0x100006f6c      b.ne  0x100006f20
| :||::|:   0x100006f70      add   x2, var_590h
| :||::|:   0x100006f74      add   x3, var_3c0h
| :||::|:   0x100006f78      mov   x0, x21
| :||::|:   0x100006f7c      mov   w4, 0x10
| :||::|:   0x100006f80      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| :||::|:   0x100006f84      mov   x22, x0
| `=======< 0x100006f88      cbnz  x0, 0x100006f1c
|  `------> 0x100006f8c      mov   x0, x21                             ; void *instance
|   |::|:   0x100006f90      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |::|:   0x100006f94      mov   x0, x27
|   |::|:   0x100006f98      mov   x2, x20
|   |::|:   0x100006f9c      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
|   |::|:   0x100006fa0      mov   x0, x20                             ; void *instance
|   |::|:   0x100006fa4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |::|:   0x100006fa8      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
|  ,======< 0x100006fac      tbz   w8, 0, 0x1000070c8
|  ||::|:   0x100006fb0      adrp  x0, data.100008000                  ; 0x100008000
|  ||::|:   0x100006fb4      add   x0, x0, 0x50e                       ; 0x10000850e ; "Bless Invocation:" ; const char *s
|  ||::|:   0x100006fb8      bl    sym.imp.puts                        ; int puts(const char *s)
|  ||::|:   0x100006fbc      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x100006fc0      ldr   x8, [x8, 0xc00]                     ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
|  ||::|:   0x100006fc4      ldr   x0, [x8]                            ; [0x10001c168:4]=0
|  ||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
|  ||::|:   0x100006fc8      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  ||::|:   0x100006fcc      mov   w0, 9
|  ||::|:   0x100006fd0      bl    sym.imp.putchar                     ; int putchar(int c)
|  ||::|:   0x100006fd4      movi  v0.2d, 0000000000000000
|  ||::|:   0x100006fd8      stp   q0, q0, [var_5d0h]
|  ||::|:   0x100006fdc      stp   q0, q0, [var_5c0h + 0x10]
|  ||::|:   0x100006fe0      mov   x0, x27                             ; void *instance
|  ||::|:   0x100006fe4      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  ||::|:   0x100006fe8      mov   x20, x0
|  ||::|:   0x100006fec      add   x2, var_5d0h
|  ||::|:   0x100006ff0      add   x3, var_440h
|  ||::|:   0x100006ff4      mov   w4, 0x10
|  ||::|:   0x100006ff8      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ,=======< 0x100006ffc      cbz   x0, 0x1000070a0
| |||::|:   ; XREFS(34)
| |||::|:   ;-- data.100007000:
| |||::|:   0x100007000      mov   x22, x0
| |||::|:   0x100007004      ldr   x8, [var_5c0h]                      ; [0x130:4]=-1 ; 304
| |||::|:   0x100007008      ldr   x25, [x8]
| |||::|:   0x10000700c      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
| |||::|:   0x100007010      add   x21, x21, 0x660                     ; 0x10000c660
| |||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c660
| |||::|:   0x100007014      adrp  x26, data.100008000                 ; 0x100008000
| |||::|:   0x100007018      add   x26, x26, 0x497                     ; 0x100008497 ; "\"%s\""
| |||::|:   0x10000701c      adrp  x27, data.100008000                 ; 0x100008000
| |||::|:   0x100007020      add   x27, x27, 0x49c
| --------> 0x100007024      mov   x28, 0
| --------> 0x100007028      ldr   x8, [var_5c0h]                      ; [0x130:4]=-1 ; 304
| |||::|:   0x10000702c      ldr   x8, [x8]
| |||::|:   0x100007030      cmp   x8, x25
| ========< 0x100007034      b.eq  0x100007040
| |||::|:   0x100007038      mov   x0, x20                             ; void *instance
| |||::|:   0x10000703c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100007040      ldr   x8, [var_5c8h]                      ; [0x128:4]=-1 ; 296
| |||::|:   0x100007044      ldr   x23, [x8, x28, lsl 3]
| |||::|:   0x100007048      mov   x0, x23
| |||::|:   0x10000704c      mov   x2, x21
| |||::|:   0x100007050      bl    stub.objc_msgSend_rangeOfString:    ;  stub.objc_msgSend_rangeOfString:(void)
| |||::|:   0x100007054      mov   x24, x1
| |||::|:   0x100007058      mov   x0, x23
| |||::|:   0x10000705c      bl    sym.imp.objc_retainAutorelease
| |||::|:   0x100007060      bl    section.2.__TEXT.__objc_stubs       ;  section.2.__TEXT.__objc_stubs(void)
| |||::|:   0x100007064      cmp   x24, 0
| |||::|:   0x100007068      csel  x8, x27, x26, eq
| |||::|:   0x10000706c      str   x0, [sp]
| |||::|:   0x100007070      mov   x0, x8                              ; const char *format
| |||::|:   0x100007074      bl    sym.imp.printf                      ; int printf(const char *format)
| |||::|:   0x100007078      add   x28, x28, 1
| |||::|:   0x10000707c      subs  x22, x22, 1
| ========< 0x100007080      b.ne  0x100007028
| |||::|:   0x100007084      add   x2, var_5d0h
| |||::|:   0x100007088      add   x3, var_440h
| |||::|:   0x10000708c      mov   x0, x20
| |||::|:   0x100007090      mov   w4, 0x10
| |||::|:   0x100007094      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||::|:   0x100007098      mov   x22, x0
| ========< 0x10000709c      cbnz  x0, 0x100007024
| `-------> 0x1000070a0      mov   x0, x20                             ; void *instance
|  ||::|:   0x1000070a4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ||::|:   0x1000070a8      mov   w0, 0xa
|  ||::|:   0x1000070ac      bl    sym.imp.putchar                     ; int putchar(int c)
|  ||::|:   0x1000070b0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x1000070b4      ldr   x8, [x8, 0xc00]                     ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
|  ||::|:   0x1000070b8      ldr   x0, [x8]                            ; [0x10001c168:4]=0
|  ||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
|  ||::|:   0x1000070bc      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  ||::|:   0x1000070c0      ldr   x27, [var_678h]                     ; [0x78:4]=-1 ; 120
|  ||::|:   0x1000070c4      ldr   x28, [var_6c0h]                     ; [0x30:4]=-1 ; 48
|  `------> 0x1000070c8      mov   x0, x27
|   |::|:   0x1000070cc      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
|  ,======< 0x1000070d0      cbz   x0, 0x100007278
|  ||::|:   0x1000070d4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x1000070d8      ldr   x0, [x8, 0xc30]                     ; [0x10000cc30:4]=0x1c198 ; reloc.NSMutableDictionary
|  ||::|:   0x1000070dc      mov   w2, 5
|  ||::|:   0x1000070e0      bl    stub.objc_msgSend_dictionaryWithCapacity: ;  stub.objc_msgSend_dictionaryWithCapacity:(void)
|  ||::|:   0x1000070e4      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  ||::|:   0x1000070e8      mov   x20, x0
|  ||::|:   0x1000070ec      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|  ||::|:   0x1000070f0      ldr   x0, [x22, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|  ||::|:   0x1000070f4      mov   w2, 1
|  ||::|:   0x1000070f8      bl    stub.objc_msgSend_numberWithInteger: ;  stub.objc_msgSend_numberWithInteger:(void)
|  ||::|:   0x1000070fc      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  ||::|:   0x100007100      mov   x21, x0
|  ||::|:   0x100007104      ldr   x0, [x22, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|  ||::|:   0x100007108      mov   x2, x19
|  ||::|:   0x10000710c      bl    stub.objc_msgSend_numberWithUnsignedInteger: ;  stub.objc_msgSend_numberWithUnsignedInteger:(void)
|  ||::|:   0x100007110      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  ||::|:   0x100007114      mov   x19, x0
|  ||::|:   0x100007118      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x10000711c      add   x3, x3, 0x360                       ; 0x10000c360
|  ||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c360
|  ||::|:   0x100007120      mov   x0, x20
|  ||::|:   0x100007124      mov   x2, x21
|  ||::|:   0x100007128      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
|  ||::|:   0x10000712c      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x100007130      add   x3, x3, 0x760                       ; 0x10000c760
|  ||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c760
|  ||::|:   0x100007134      mov   x0, x20
|  ||::|:   0x100007138      mov   x2, x19
|  ||::|:   0x10000713c      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
|  ||::|:   0x100007140      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x100007144      add   x3, x3, 0xa80                       ; 0x10000ca80
|  ||::|:                                                              ; reloc.__CFConstantStringClassReference.10000ca80
|  ||::|:   0x100007148      mov   x0, x20
|  ||::|:   0x10000714c      mov   x2, x27
|  ||::|:   0x100007150      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
|  ||::|:   0x100007154      mov   x0, x28
|  ||::|:   0x100007158      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
|  ||::|:   0x10000715c      ldp   x26, x25, [var_690h]
| ,=======< 0x100007160      cbz   x0, 0x100007178
| |||::|:   0x100007164      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::|:   0x100007168      add   x3, x3, 0x780                       ; 0x10000c780
| |||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c780
| |||::|:   0x10000716c      mov   x0, x20
| |||::|:   0x100007170      mov   x2, x28
| |||::|:   0x100007174      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| `-------> 0x100007178      ldr   x22, [var_6b8h]                     ; [0x38:4]=-1 ; 56
|  ||::|:   0x10000717c      mov   x0, x22
|  ||::|:   0x100007180      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
| ,=======< 0x100007184      cbz   x0, 0x10000719c
| |||::|:   0x100007188      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||::|:   0x10000718c      add   x3, x3, 0x7a0                       ; 0x10000c7a0
| |||::|:                                                              ; reloc.__CFConstantStringClassReference.10000c7a0
| |||::|:   0x100007190      mov   x0, x20
| |||::|:   0x100007194      mov   x2, x22
| |||::|:   0x100007198      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| `-------> 0x10000719c      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
| ,=======< 0x1000071a0      tbz   w8, 0, 0x1000071b0
| |||::|:   0x1000071a4      adrp  x0, data.100008000                  ; 0x100008000
| |||::|:   0x1000071a8      add   x0, x0, 0x520                       ; 0x100008520 ; "\n\nResulting FirmwareUpdateLauncher Plist:\n" ; const char *s
| |||::|:   0x1000071ac      bl    sym.imp.puts                        ; int puts(const char *s)
| `-------> 0x1000071b0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x1000071b4      ldr   x0, [x8, 0xbe0]                     ; [0x10000cbe0:4]=0x1c148 ; "H\xc1\U00000001"
|  ||::|:   0x1000071b8      str   xzr, [var_5d8h]
|  ||::|:   0x1000071bc      add   x5, var_5d8h
|  ||::|:   0x1000071c0      mov   x2, x20
|  ||::|:   0x1000071c4      mov   w3, 0x64                            ; 'd'
|  ||::|:   0x1000071c8      mov   x4, 0
|  ||::|:   0x1000071cc      bl    stub.objc_msgSend_dataWithPropertyList:format:options:error: ;  stub.objc_msgSend_dataWithPropertyList:format:options:error:(void)
|  ||::|:   0x1000071d0      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  ||::|:   0x1000071d4      mov   x22, x0
|  ||::|:   0x1000071d8      ldr   x0, [var_5d8h]                      ; [0x118:4]=-1 ; 280 ; void *instance
|  ||::|:   0x1000071dc      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  ||::|:   0x1000071e0      mov   x23, x0
|  ||::|:   0x1000071e4      mov   x0, x22
|  ||::|:   0x1000071e8      bl    stub.objc_msgSend_length            ;  stub.objc_msgSend_length(void)
|  ||::|:   0x1000071ec      mov   w1, 0xe820
|  ||::|:   0x1000071f0      movk  w1, 0xa463, lsl 16
|  ||::|:   0x1000071f4      bl    sym.imp.malloc_type_malloc
|  ||::|:   0x1000071f8      mov   x24, x0
|  ||::|:   0x1000071fc      mov   x0, x22
|  ||::|:   0x100007200      bl    stub.objc_msgSend_length            ;  stub.objc_msgSend_length(void)
|  ||::|:   0x100007204      mov   x3, x0
|  ||::|:   0x100007208      mov   x0, x22
|  ||::|:   0x10000720c      mov   x2, x24
|  ||::|:   0x100007210      bl    stub.objc_msgSend_getBytes:length:  ;  stub.objc_msgSend_getBytes:length:(void)
|  ||::|:   0x100007214      mov   x0, x24                             ; const char *s
|  ||::|:   0x100007218      bl    sym.imp.puts                        ; int puts(const char *s)
|  ||::|:   0x10000721c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  ||::|:   0x100007220      ldr   x8, [x8, 0xc00]                     ; [0x10000cc00:4]=0x1c168 ; "h\xc1\U00000001"
|  ||::|:   0x100007224      ldr   x0, [x8]                            ; [0x10001c168:4]=0
|  ||::|:                                                              ; reloc.target.__stdoutp ; FILE *stream
|  ||::|:   0x100007228      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  ||::|:   0x10000722c      mov   x0, x24                             ; void *ptr
|  ||::|:   0x100007230      bl    sym.imp.free                        ; void free(void *ptr)
|  ||::|:   0x100007234      mov   x0, x22                             ; void *instance
|  ||::|:   0x100007238      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ||::|:   0x10000723c      mov   x0, x23                             ; void *instance
|  ||::|:   0x100007240      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ||::|:   0x100007244      mov   x0, x19                             ; void *instance
|  ||::|:   0x100007248      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ||::|:   0x10000724c      mov   x0, x21                             ; void *instance
|  ||::|:   0x100007250      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ||::|:   0x100007254      mov   x0, x20                             ; void *instance
|  ||::|:   0x100007258      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ||::|:   0x10000725c      mov   w19, 0
|  ||::|:   0x100007260      ldp   x20, x21, [var_6b8h]
|  ||::|:   0x100007264      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
|  ||::|:   0x100007268      ldr   x22, [var_6d0h]                     ; [0x20:4]=-1 ; 32
|  ||::|:   0x10000726c      ldr   x23, [instance]                     ; [0x110:4]=-1 ; 272
|  ||`====< 0x100007270      tbz   w8, 0, 0x100005d28
|  ||,====< 0x100007274      b     0x100007294
|  `------> 0x100007278      mov   w19, 1
|   ||:|:   0x10000727c      ldp   x20, x21, [var_6b8h]
|   ||:|:   0x100007280      ldp   x26, x25, [var_690h]
|   ||:|:   0x100007284      ldr   x22, [var_6d0h]                     ; [0x20:4]=-1 ; 32
|   ||:|:   0x100007288      ldr   x23, [instance]                     ; [0x110:4]=-1 ; 272
|   ||:|:   ; CODE XREFS from entry0 @ 0x10000624c, 0x100006e04
|   `--`--> 0x10000728c      ldr   w8, [var_694h]                      ; [0x5c:4]=-1 ; 92
|    |`===< 0x100007290      tbz   w8, 0, 0x100005d28
|    |  :   ; CODE XREF from entry0 @ 0x100007274
|    `----> 0x100007294      str   x19, [sp]
|       :   0x100007298      adrp  x0, data.100008000                  ; 0x100008000
|       :   0x10000729c      add   x0, x0, 0x4af                       ; 0x1000084af ; "\n\nExit status: %u\n" ; const char *format
|       :   0x1000072a0      bl    sym.imp.printf                      ; int printf(const char *format)
\       `=< 0x1000072a4      b     0x100005d28
