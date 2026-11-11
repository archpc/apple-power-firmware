[2K            ; CALL XREF from sym.func.10000218c @ 0x1000021e4
            ; CALL XREF from sym.func.1000041cc @ 0x100005420
/ sym.func.100001ad8(void *instance, int64_t arg2);
|           ; arg void *instance @ x0
|           ; arg int64_t arg2 @ x1
|           ; var int64_t var_138h @ stack - 0x138
|           ; var int64_t var_130h @ stack - 0x130
|           ; var int64_t var_128h @ stack - 0x128
|           ; var int64_t var_120h @ stack - 0x120
|           ; var int64_t var_f0h @ stack - 0xf0
|           ; var int64_t var_60h @ stack - 0x60
|           ; var int64_t var_50h @ stack - 0x50
|           ; var int64_t var_40h @ stack - 0x40
|           ; var int64_t var_30h @ stack - 0x30
|           ; var int64_t var_20h @ stack - 0x20
|           ; var int64_t var_10h @ stack - 0x10
|           0x100001ad8      pacibsp
|           0x100001adc      sub   sp, sp, 0x140
|           0x100001ae0      stp   x28, x27, [var_60h]
|           0x100001ae4      stp   x26, x25, [var_50h]
|           0x100001ae8      stp   x24, x23, [var_40h]
|           0x100001aec      stp   x22, x21, [var_30h]
|           0x100001af0      stp   x20, x19, [var_20h]
|           0x100001af4      stp   x29, x30, [var_10h]
|           0x100001af8      add   x29, sp, 0x130
|           0x100001afc      mov   x20, x1                             ; arg2
|           0x100001b00      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100001b04      ldr   x8, [x8, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x100001b08      ldr   x8, [x8]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x100001b0c      stur  x8, [var_60h]
|           0x100001b10      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100001b14      mov   x19, x0
|           0x100001b18      mov   x0, x20                             ; void *instance
|           0x100001b1c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100001b20      mov   x20, x0
|           0x100001b24      adrp  x8, section.12.__DATA.__objc_selrefs ; 0x100010000
|           0x100001b28      ldrb  w8, [x8, 0x178]                     ; [0x100010178:4]=0
|                                                                      ; section.13.__DATA.__common
|       ,=< 0x100001b2c      tbz   w8, 0, 0x100001bc4
|       |   ; CODE XREF from sym.func.100001ad8 @ 0x100001eac
|      .--> 0x100001b30      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|      :|   0x100001b34      add   x2, x2, 0x500                       ; 0x10000c500
|      :|                                                              ; reloc.__CFConstantStringClassReference.10000c500
|      :|   0x100001b38      mov   x0, x19
|      :|   0x100001b3c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      :|   0x100001b40      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      :|   0x100001b44      mov   x21, x0
|      :|   0x100001b48      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|      :|   0x100001b4c      add   x2, x2, 0x520                       ; 0x10000c520
|      :|                                                              ; reloc.__CFConstantStringClassReference.10000c520
|      :|   0x100001b50      mov   x0, x19
|      :|   0x100001b54      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      :|   0x100001b58      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      :|   0x100001b5c      mov   x22, x0
|      :|   0x100001b60      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
|      :|   0x100001b64      add   x2, x2, 0x360                       ; 0x10000c360
|      :|                                                              ; reloc.__CFConstantStringClassReference.10000c360
|      :|   0x100001b68      mov   x0, x20
|      :|   0x100001b6c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      :|   0x100001b70      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      :|   0x100001b74      mov   x23, x0
|      :|   0x100001b78      adrp  x24, section.7.__DATA_CONST.__const ; 0x10000c000
|      :|   0x100001b7c      ldr   x24, [x24, 0xbf8]                   ; [0x10000cbf8:4]=0x1c160 ; "`\xc1\U00000001"
|     ,===< 0x100001b80      cbz   x0, 0x100001c74
|    ,====< 0x100001b84      cbz   x21, 0x100001c98
|    ||:|   0x100001b88      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|    ||:|   0x100001b8c      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|    ||:|   0x100001b90      bl    sym.imp.objc_opt_class
|    ||:|   0x100001b94      mov   x1, x0
|    ||:|   0x100001b98      mov   x0, x21
|    ||:|   0x100001b9c      bl    sym.imp.objc_opt_isKindOfClass
|   ,=====< 0x100001ba0      tbz   w0, 0, 0x100001e7c
|   |||:|   0x100001ba4      mov   x1, x21                             ; int64_t arg3
|   |||:|   0x100001ba8      mov   x2, x23
|   |||:|   0x100001bac      bl    sym.func.1000020e8
|  ,======< 0x100001bb0      cbz   w0, 0x100001c98
|  ||||:|   0x100001bb4      ldr   x3, [x24]                           ; [0x10001c160:4]=0
|  ||||:|                                                              ; str.tubs
|  ||||:|   0x100001bb8      adrp  x0, data.100007000                  ; 0x100007000
|  ||||:|   0x100001bbc      add   x0, x0, 0xddb                       ; 0x100007ddb ; "** Min firmware version not met.  Aborting\n"
| ,=======< 0x100001bc0      b     0x100001cd4
| |||||:`-> 0x100001bc4      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||:    0x100001bc8      add   x21, x21, 0x360                     ; 0x10000c360
| |||||:                                                               ; reloc.__CFConstantStringClassReference.10000c360
| |||||:    0x100001bcc      mov   x0, x19
| |||||:    0x100001bd0      mov   x2, x21
| |||||:    0x100001bd4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||:    0x100001bd8      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||:    0x100001bdc      mov   x23, x0
| |||||:    0x100001be0      mov   x0, x20
| |||||:    0x100001be4      mov   x2, x21
| |||||:    0x100001be8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||:    0x100001bec      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||:    0x100001bf0      mov   x22, x0
| |||||:    0x100001bf4      mov   x21, 0
| |||||:,=< 0x100001bf8      cbz   x23, 0x100001c5c
| ========< 0x100001bfc      cbz   x22, 0x100001c5c
| |||||:|   0x100001c00      mov   x0, x23                             ; void *instance
| |||||:|   0x100001c04      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||:|   0x100001c08      mov   x21, x0
| |||||:|   0x100001c0c      mov   x1, x0                              ; int64_t arg3
| |||||:|   0x100001c10      mov   x2, x22
| |||||:|   0x100001c14      bl    sym.func.1000020e8
| ========< 0x100001c18      cbz   w0, 0x100001c5c
| |||||:|   0x100001c1c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||||:|   0x100001c20      add   x2, x2, 0x380                       ; 0x10000c380
| |||||:|                                                              ; reloc.__CFConstantStringClassReference.10000c380
| |||||:|   0x100001c24      mov   x0, x20
| |||||:|   0x100001c28      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||:|   0x100001c2c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||:|   0x100001c30      mov   x23, x0
| ========< 0x100001c34      cbz   x0, 0x100001e8c
| |||||:|   0x100001c38      mov   x0, x23
| |||||:|   0x100001c3c      bl    stub.objc_msgSend_unsignedIntegerValue ;  stub.objc_msgSend_unsignedIntegerValue(void)
| ========< 0x100001c40      cbz   x0, 0x100001e8c
| |||||:|   0x100001c44      mov   x0, x23                             ; void *instance
| |||||:|   0x100001c48      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001c4c      mov   x0, x22                             ; void *instance
| |||||:|   0x100001c50      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001c54      mov   x0, x21
| ========< 0x100001c58      b     0x100001edc
| ------`-> 0x100001c5c      mov   x0, x22                             ; void *instance
| |||||:    0x100001c60      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:    0x100001c64      mov   x0, x21                             ; void *instance
| |||||:    0x100001c68      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:    0x100001c6c      mov   x0, x23
| |||||:,=< 0x100001c70      b     0x100001ee4
| ||||`---> 0x100001c74      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| |||| :|                                                              ; str.tubs ; FILE *stream
| |||| :|   0x100001c78      adrp  x0, data.100007000                  ; 0x100007000
| |||| :|   0x100001c7c      add   x0, x0, 0xd8c                       ; 0x100007d8c ; "** No current firmware version?\n" ; const void *ptr
| |||| :|   0x100001c80      mov   w1, 0x20
| |||| :|   0x100001c84      mov   w2, 1
| |||| :|   0x100001c88      bl    sym.imp.fwrite                      ; size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
| |||| :|   0x100001c8c      ldr   x0, [x24]                           ; [0x10001c160:4]=0
| |||| :|                                                              ; str.tubs ; FILE *stream
| |||| :|   0x100001c90      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| ||||,===< 0x100001c94      b     0x100001cdc
| =`-`----> 0x100001c98      cbz   x22, 0x100001cdc
| | | |:|   0x100001c9c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| | | |:|   0x100001ca0      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| | | |:|   0x100001ca4      bl    sym.imp.objc_opt_class
| | | |:|   0x100001ca8      mov   x1, x0
| | | |:|   0x100001cac      mov   x0, x22
| | | |:|   0x100001cb0      bl    sym.imp.objc_opt_isKindOfClass
| | |,====< 0x100001cb4      tbz   w0, 0, 0x100001eb0
| | |||:|   0x100001cb8      mov   x1, x22                             ; int64_t arg3
| | |||:|   0x100001cbc      mov   x2, x23
| | |||:|   0x100001cc0      bl    sym.func.100002044
| |,======< 0x100001cc4      cbz   w0, 0x100001cdc
| |||||:|   0x100001cc8      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| |||||:|                                                              ; str.tubs
| |||||:|   0x100001ccc      adrp  x0, data.100007000                  ; 0x100007000
| |||||:|   0x100001cd0      add   x0, x0, 0xe35                       ; 0x100007e35 ; "** Max firmware version not met.  Aborting\n"
| |||||:|   ; CODE XREF from sym.func.100001ad8 @ 0x100001bc0
| `-------> 0x100001cd4      mov   w1, 0x2b                            ; '+'
| ,=======< 0x100001cd8      b     0x100001ec0
| |||||:|   ; CODE XREF from sym.func.100001ad8 @ 0x100001c94
| -`--`---> 0x100001cdc      mov   x0, x23                             ; void *instance
| | || :|   0x100001ce0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | || :|   0x100001ce4      mov   x0, x22                             ; void *instance
| | || :|   0x100001ce8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | || :|   0x100001cec      mov   x0, x21                             ; void *instance
| | || :|   0x100001cf0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | || :|   0x100001cf4      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| | || :|   0x100001cf8      add   x22, x22, 0x4a0                     ; 0x10000c4a0
| | || :|                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
| | || :|   0x100001cfc      mov   x0, x19
| | || :|   0x100001d00      mov   x2, x22
| | || :|   0x100001d04      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| | || :|   0x100001d08      bl    sym.imp.objc_claimAutoreleasedReturnValue
| | || :|   0x100001d0c      mov   x27, x0
| | || :|   0x100001d10      mov   x0, x20
| | || :|   0x100001d14      mov   x2, x22
| | || :|   0x100001d18      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| | || :|   0x100001d1c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| | || :|   0x100001d20      mov   x22, x0
| | ||,===< 0x100001d24      cbz   x27, 0x100001d3c
| |,======< 0x100001d28      cbnz  x22, 0x100001d3c
| --------> 0x100001d2c      mov   w24, 0
| |||||:|   0x100001d30      mov   x25, 0
| |||||:|   0x100001d34      mov   x26, 0
| ========< 0x100001d38      b     0x100001f0c
| |`--`---> 0x100001d3c      mov   x25, 0
| | || :|   0x100001d40      mov   x23, 0
| | ||,===< 0x100001d44      cbz   x27, 0x100001f04
| |,======< 0x100001d48      cbz   x22, 0x100001f04
| |||||:|   0x100001d4c      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||:|   0x100001d50      ldr   x0, [x21, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |||||:|   0x100001d54      bl    sym.imp.objc_opt_class
| |||||:|   0x100001d58      mov   x1, x0
| |||||:|   0x100001d5c      mov   x0, x27
| |||||:|   0x100001d60      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100001d64      tbnz  w0, 0, 0x100001d84
| |||||:|   0x100001d68      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||||:|   0x100001d6c      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||||:|   0x100001d70      bl    sym.imp.objc_opt_class
| |||||:|   0x100001d74      mov   x1, x0
| |||||:|   0x100001d78      mov   x0, x27
| |||||:|   0x100001d7c      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100001d80      tbz   w0, 0, 0x100001d2c
| --------> 0x100001d84      ldr   x0, [x21, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |||||:|   0x100001d88      bl    sym.imp.objc_opt_class
| |||||:|   0x100001d8c      mov   x1, x0
| |||||:|   0x100001d90      mov   x0, x27
| |||||:|   0x100001d94      bl    sym.imp.objc_opt_isKindOfClass
| |||||:|   0x100001d98      mov   x24, x0
| |||||:|   0x100001d9c      mov   x0, x27                             ; void *instance
| |||||:|   0x100001da0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||:|   0x100001da4      mov   x23, x0
| ========< 0x100001da8      tbz   w24, 0, 0x100001ef0
| |||||:|   0x100001dac      movi  v0.2d, 0000000000000000
| |||||:|   0x100001db0      stp   q0, q0, [var_120h + 0x10]
| |||||:|   0x100001db4      stp   q0, q0, [var_130h]
| |||||:|   0x100001db8      add   x2, var_130h
| |||||:|   0x100001dbc      add   x3, var_f0h
| |||||:|   0x100001dc0      mov   x0, x23
| |||||:|   0x100001dc4      mov   w4, 0x10
| |||||:|   0x100001dc8      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||:|   0x100001dcc      mov   x24, x0
| ========< 0x100001dd0      cbz   x0, 0x100001f80
| |||||:|   0x100001dd4      str   x27, [var_138h]
| |||||:|   0x100001dd8      mov   x25, 0
| |||||:|   0x100001ddc      mov   w27, 0
| |||||:|   0x100001de0      ldr   x8, [var_120h]                      ; [0x20:4]=-1 ; 32
| |||||:|   0x100001de4      ldr   x28, [x8]
| --------> 0x100001de8      mov   x21, 0
| |||||:|   0x100001dec      mov   x26, x25
| --------> 0x100001df0      ldr   x8, [var_120h]                      ; [0x20:4]=-1 ; 32
| |||||:|   0x100001df4      ldr   x8, [x8]
| |||||:|   0x100001df8      cmp   x8, x28
| ========< 0x100001dfc      b.eq  0x100001e08
| |||||:|   0x100001e00      mov   x0, x23                             ; void *instance
| |||||:|   0x100001e04      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100001e08      ldr   x8, [var_128h]                      ; [0x18:4]=-1 ; 24
| |||||:|   0x100001e0c      ldr   x0, [x8, x21, lsl 3]                ; void *instance
| |||||:|   0x100001e10      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||:|   0x100001e14      mov   x25, x0
| |||||:|   0x100001e18      mov   x0, x26                             ; void *instance
| |||||:|   0x100001e1c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001e20      mov   x1, x25                             ; int64_t arg3
| |||||:|   0x100001e24      mov   x2, x22
| |||||:|   0x100001e28      bl    sym.func.100001fa0
| |||||:|   0x100001e2c      orr   w27, w27, w0
| |||||:|   0x100001e30      add   x21, x21, 1
| |||||:|   0x100001e34      mov   x26, x25
| |||||:|   0x100001e38      subs  x24, x24, 1
| ========< 0x100001e3c      b.ne  0x100001df0
| |||||:|   0x100001e40      add   x2, var_130h
| |||||:|   0x100001e44      add   x3, var_f0h
| |||||:|   0x100001e48      mov   x0, x23
| |||||:|   0x100001e4c      mov   w4, 0x10
| |||||:|   0x100001e50      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||:|   0x100001e54      mov   x24, x0
| ========< 0x100001e58      cbnz  x0, 0x100001de8
| |||||:|   0x100001e5c      mov   x0, x25                             ; void *instance
| |||||:|   0x100001e60      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001e64      mov   x26, 0
| ========< 0x100001e68      tbz   w27, 0, 0x100001f8c
| |||||:|   0x100001e6c      mov   x25, x23
| |||||:|   0x100001e70      mov   x23, x26
| |||||:|   0x100001e74      ldr   x27, [var_138h]                     ; [0x8:4]=-1 ; 8
| ========< 0x100001e78      b     0x100001f04
| ||`-----> 0x100001e7c      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| || ||:|                                                              ; str.tubs
| || ||:|   0x100001e80      adrp  x0, data.100007000                  ; 0x100007000
| || ||:|   0x100001e84      add   x0, x0, 0xdad                       ; 0x100007dad ; "** minversion bad object type in personality\n"
| ||,=====< 0x100001e88      b     0x100001ebc
| --------> 0x100001e8c      mov   x0, x23                             ; void *instance
| |||||:|   0x100001e90      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001e94      mov   x0, x22                             ; void *instance
| |||||:|   0x100001e98      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001e9c      mov   x0, x21                             ; void *instance
| |||||:|   0x100001ea0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||:|   0x100001ea4      mov   x0, x21                             ; void *instance
| |||||:|   0x100001ea8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||`==< 0x100001eac      b     0x100001b30
| |||`----> 0x100001eb0      ldr   x3, [x24]                           ; [0x10001c160:4]=0
| ||| | |                                                              ; str.tubs
| ||| | |   0x100001eb4      adrp  x0, data.100007000                  ; 0x100007000
| ||| | |   0x100001eb8      add   x0, x0, 0xe07                       ; 0x100007e07 ; "** maxversion bad object type in personality\n"
| ||| | |   ; CODE XREF from sym.func.100001ad8 @ 0x100001e88
| ||`-----> 0x100001ebc      mov   w1, 0x2d                            ; '-'
| ||  | |   ; CODE XREF from sym.func.100001ad8 @ 0x100001cd8
| `-------> 0x100001ec0      mov   w2, 1
|  |  | |   0x100001ec4      bl    sym.imp.fwrite                      ; size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
|  |  | |   0x100001ec8      ldr   x0, [x24]                           ; [0x10001c160:4]=0
|  |  | |                                                              ; str.tubs ; FILE *stream
|  |  | |   0x100001ecc      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  |  | |   0x100001ed0      mov   x0, x23                             ; void *instance
|  |  | |   0x100001ed4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |  | |   0x100001ed8      mov   x0, x22
|  |  | |   ; CODE XREF from sym.func.100001ad8 @ 0x100001c58
| --------> 0x100001edc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |  | |   0x100001ee0      mov   x0, x21
|  |  | |   ; CODE XREF from sym.func.100001ad8 @ 0x100001c70
|  |  | `-> 0x100001ee4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |  |     0x100001ee8      mov   w24, 0
|  |  | ,=< 0x100001eec      b     0x100001f2c
| --------> 0x100001ef0      mov   x1, x23                             ; int64_t arg3
|  |  | |   0x100001ef4      mov   x2, x22
|  |  | |   0x100001ef8      bl    sym.func.100001fa0
|  |  | |   0x100001efc      mov   x25, 0
|  |  |,==< 0x100001f00      cbz   w0, 0x100001f78
|  |  |||   ; CODE XREF from sym.func.100001ad8 @ 0x100001e78
| -`--`---> 0x100001f04      mov   w24, 1
|      ||   ; CODE XREF from sym.func.100001ad8 @ 0x100001f7c
|     .---> 0x100001f08      mov   x26, x23
|     :||   ; CODE XREFS from sym.func.100001ad8 @ 0x100001d38, 0x100001f88, 0x100001f98
| --..----> 0x100001f0c      mov   x0, x22                             ; void *instance
|   :::||   0x100001f10      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   :::||   0x100001f14      mov   x0, x26                             ; void *instance
|   :::||   0x100001f18      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   :::||   0x100001f1c      mov   x0, x25                             ; void *instance
|   :::||   0x100001f20      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   :::||   0x100001f24      mov   x0, x27                             ; void *instance
|   :::||   0x100001f28      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   :::||   ; CODE XREF from sym.func.100001ad8 @ 0x100001eec
|   :::|`-> 0x100001f2c      mov   x0, x20                             ; void *instance
|   :::|    0x100001f30      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   :::|    0x100001f34      mov   x0, x19                             ; void *instance
|   :::|    0x100001f38      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   :::|    0x100001f3c      ldur  x8, [var_60h]
|   :::|    0x100001f40      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
|   :::|    0x100001f44      ldr   x9, [x9, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|   :::|    0x100001f48      ldr   x9, [x9]                            ; [0x10001c158:4]=0
|   :::|                                                               ; str.objc_stubs
|   :::|    0x100001f4c      cmp   x9, x8
|   :::|,=< 0x100001f50      b.ne  0x100001f9c
|   :::||   0x100001f54      mov   x0, x24
|   :::||   0x100001f58      ldp   x29, x30, [var_10h]
|   :::||   0x100001f5c      ldp   x20, x19, [var_20h]
|   :::||   0x100001f60      ldp   x22, x21, [var_30h]
|   :::||   0x100001f64      ldp   x24, x23, [var_40h]
|   :::||   0x100001f68      ldp   x26, x25, [var_50h]
|   :::||   0x100001f6c      ldp   x28, x27, [var_60h]
|   :::||   0x100001f70      add   sp, sp, 0x140
|   :::||   0x100001f74      retab
|   :::`--> 0x100001f78      mov   w24, 0
|   ::`===< 0x100001f7c      b     0x100001f08
| --------> 0x100001f80      mov   x26, 0
|   ::  |   0x100001f84      mov   x25, x23
|   `=====< 0x100001f88      b     0x100001f0c
| --------> 0x100001f8c      mov   w24, 0
|    :  |   0x100001f90      mov   x25, x23
|    :  |   0x100001f94      ldr   x27, [var_138h]                     ; [0x8:4]=-1 ; 8
|    `====< 0x100001f98      b     0x100001f0c
\       `-> 0x100001f9c      bl    sym.imp.__stack_chk_fail            ; void __stack_chk_fail(void)
