[2K            ; CALL XREF from sym.func.1000041cc @ 0x100004ee0
/ sym.func.100003a18(void *instance, int64_t arg2, int64_t arg3);
|           ; arg void *instance @ x0
|           ; arg int64_t arg2 @ x1
|           ; arg int64_t arg3 @ x2
|           ; var int64_t var_378h @ stack - 0x378
|           ; var int64_t var_370h @ stack - 0x370
|           ; var int64_t var_368h @ stack - 0x368
|           ; var int64_t var_360h @ stack - 0x360
|           ; var int64_t var_330h @ stack - 0x330
|           ; var int64_t var_328h @ stack - 0x328
|           ; var int64_t var_320h @ stack - 0x320
|           ; var int64_t var_2f0h @ stack - 0x2f0
|           ; var int64_t var_2e8h @ stack - 0x2e8
|           ; var int64_t var_2e0h @ stack - 0x2e0
|           ; var int64_t var_2b0h @ stack - 0x2b0
|           ; var int64_t var_2a8h @ stack - 0x2a8
|           ; var int64_t var_2a0h @ stack - 0x2a0
|           ; var int64_t var_270h @ stack - 0x270
|           ; var int64_t var_1f0h @ stack - 0x1f0
|           ; var int64_t var_170h @ stack - 0x170
|           ; var int64_t var_60h @ stack - 0x60
|           ; var int64_t var_50h @ stack - 0x50
|           ; var int64_t var_40h @ stack - 0x40
|           ; var int64_t var_30h @ stack - 0x30
|           ; var int64_t var_20h @ stack - 0x20
|           ; var int64_t var_10h @ stack - 0x10
|           0x100003a18      pacibsp
|           0x100003a1c      stp   x28, x27, [var_60h]!
|           0x100003a20      stp   x26, x25, [var_50h]
|           0x100003a24      stp   x24, x23, [var_40h]
|           0x100003a28      stp   x22, x21, [var_30h]
|           0x100003a2c      stp   x20, x19, [var_20h]
|           0x100003a30      stp   x29, x30, [var_10h]
|           0x100003a34      add   x29, sp, 0x50
|           0x100003a38      sub   sp, sp, 0x320
|           0x100003a3c      mov   x21, x2                             ; arg3
|           0x100003a40      mov   x20, x1                             ; arg2
|           0x100003a44      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x100003a48      ldr   x8, [x8, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x100003a4c      ldr   x8, [x8]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x100003a50      stur  x8, [var_60h]
|           0x100003a54      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100003a58      mov   x19, x0
|           0x100003a5c      mov   x0, x20                             ; void *instance
|           0x100003a60      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x100003a64      mov   x20, x0
|           0x100003a68      mov   x0, x19                             ; void *instance
|           0x100003a6c      mov   x1, x20                             ; int64_t arg2
|           0x100003a70      mov   x2, x21                             ; int64_t arg3
|           0x100003a74      bl    sym.func.10000218c
|       ,=< 0x100003a78      cbz   w0, 0x100003bf4
|       |   0x100003a7c      mov   x0, x19                             ; void *instance
|       |   0x100003a80      mov   x1, x20                             ; int64_t arg2
|       |   0x100003a84      bl    sym.func.100002ea8
|      ,==< 0x100003a88      cbz   w0, 0x100003bf4
|      ||   0x100003a8c      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
|      ||   0x100003a90      add   x21, x21, 0x280                     ; 0x10000c280
|      ||                                                              ; reloc.__CFConstantStringClassReference.10000c280
|      ||   0x100003a94      mov   x0, x19
|      ||   0x100003a98      mov   x2, x21
|      ||   0x100003a9c      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      ||   0x100003aa0      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      ||   0x100003aa4      mov   x27, x0
|      ||   0x100003aa8      mov   x0, x20
|      ||   0x100003aac      mov   x2, x21
|      ||   0x100003ab0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|      ||   0x100003ab4      bl    sym.imp.objc_claimAutoreleasedReturnValue
|      ||   0x100003ab8      mov   x21, x0
|     ,===< 0x100003abc      cbz   x27, 0x100003ac4
|    ,====< 0x100003ac0      cbz   x21, 0x100003fd0
|   ,=`---> 0x100003ac4      cbz   x27, 0x100003bfc
|   || ||   0x100003ac8      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|   || ||   0x100003acc      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|   || ||   0x100003ad0      bl    sym.imp.objc_opt_class
|   || ||   0x100003ad4      mov   x1, x0
|   || ||   0x100003ad8      mov   x0, x27
|   || ||   0x100003adc      bl    sym.imp.objc_opt_isKindOfClass
|   ||,===< 0x100003ae0      tbnz  w0, 0, 0x100003b00
|   |||||   0x100003ae4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|   |||||   0x100003ae8      ldr   x0, [x8, 0xbe8]                     ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
|   |||||   0x100003aec      bl    sym.imp.objc_opt_class
|   |||||   0x100003af0      mov   x1, x0
|   |||||   0x100003af4      mov   x0, x27
|   |||||   0x100003af8      bl    sym.imp.objc_opt_isKindOfClass
|  ,======< 0x100003afc      tbz   w0, 0, 0x100003fd0
|  |||`---> 0x100003b00      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  ||| ||   0x100003b04      bl    sym.imp.objc_opt_class
|  ||| ||   0x100003b08      mov   x1, x0
|  ||| ||   0x100003b0c      mov   x0, x27
|  ||| ||   0x100003b10      bl    sym.imp.objc_opt_isKindOfClass
|  ||| ||   0x100003b14      mov   x23, x0
|  ||| ||   0x100003b18      mov   x0, x27                             ; void *instance
|  ||| ||   0x100003b1c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  ||| ||   0x100003b20      mov   x24, x0
|  |||,===< 0x100003b24      tbz   w23, 0, 0x100003c08
|  ||||||   0x100003b28      movi  v0.2d, 0000000000000000
|  ||||||   0x100003b2c      stp   q0, q0, [var_2a0h + 0x10]
|  ||||||   0x100003b30      stp   q0, q0, [var_2b0h]
|  ||||||   0x100003b34      add   x2, var_2b0h
|  ||||||   0x100003b38      sub   x3, var_10h + 0xf0
|  ||||||   0x100003b3c      mov   x0, x24
|  ||||||   0x100003b40      mov   w4, 0x10
|  ||||||   0x100003b44      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ,=======< 0x100003b48      cbz   x0, 0x10000417c
| |||||||   0x100003b4c      mov   x23, x0
| |||||||   0x100003b50      str   x27, [var_378h]
| |||||||   0x100003b54      mov   w27, 0
| |||||||   0x100003b58      mov   x25, 0
| |||||||   0x100003b5c      ldr   x8, [var_2a0h]                      ; [0xe0:4]=-1 ; 224
| |||||||   0x100003b60      ldr   x28, [x8]
| --------> 0x100003b64      mov   x22, 0
| |||||||   0x100003b68      mov   x26, x25
| --------> 0x100003b6c      ldr   x8, [var_2a0h]                      ; [0xe0:4]=-1 ; 224
| |||||||   0x100003b70      ldr   x8, [x8]
| |||||||   0x100003b74      cmp   x8, x28
| ========< 0x100003b78      b.eq  0x100003b84
| |||||||   0x100003b7c      mov   x0, x24                             ; void *instance
| |||||||   0x100003b80      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100003b84      ldr   x8, [var_2a8h]                      ; [0xd8:4]=-1 ; 216
| |||||||   0x100003b88      ldr   x0, [x8, x22, lsl 3]                ; void *instance
| |||||||   0x100003b8c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100003b90      mov   x25, x0
| |||||||   0x100003b94      mov   x0, x26                             ; void *instance
| |||||||   0x100003b98      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003b9c      mov   x1, x25                             ; int64_t arg3
| |||||||   0x100003ba0      mov   x2, x21
| |||||||   0x100003ba4      bl    sym.func.100002e04
| |||||||   0x100003ba8      orr   w27, w27, w0
| |||||||   0x100003bac      add   x22, x22, 1
| |||||||   0x100003bb0      mov   x26, x25
| |||||||   0x100003bb4      subs  x23, x23, 1
| ========< 0x100003bb8      b.ne  0x100003b6c
| |||||||   0x100003bbc      add   x2, var_2b0h
| |||||||   0x100003bc0      sub   x3, var_10h + 0xf0
| |||||||   0x100003bc4      mov   x0, x24
| |||||||   0x100003bc8      mov   w4, 0x10
| |||||||   0x100003bcc      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x100003bd0      mov   x23, x0
| ========< 0x100003bd4      cbnz  x0, 0x100003b64
| |||||||   0x100003bd8      mov   x0, x25                             ; void *instance
| |||||||   0x100003bdc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003be0      mov   x25, 0
| ========< 0x100003be4      tbz   w27, 0, 0x100004180
| |||||||   0x100003be8      mov   x23, x24
| |||||||   0x100003bec      ldr   x27, [var_378h]                     ; [0x8:4]=-1 ; 8
| ========< 0x100003bf0      b     0x100003c20
| |||||``-> 0x100003bf4      mov   w26, 0
| ||||| ,=< 0x100003bf8      b     0x100003ffc
| ||`-----> 0x100003bfc      mov   x25, 0
| || || |   0x100003c00      mov   x23, 0
| || ||,==< 0x100003c04      b     0x100003c20
| || |`---> 0x100003c08      mov   x1, x24                             ; int64_t arg3
| || | ||   0x100003c0c      mov   x2, x21
| || | ||   0x100003c10      bl    sym.func.100002e04
| || | ||   0x100003c14      mov   x23, 0
| || |,===< 0x100003c18      cbz   w0, 0x1000041b8
| || ||||   0x100003c1c      mov   x25, x24
| || ||||   ; CODE XREFS from sym.func.100003a18 @ 0x100003bf0, 0x100003c04
| -----`--> 0x100003c20      mov   x0, x21                             ; void *instance
| || || |   0x100003c24      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| || || |   0x100003c28      mov   x0, x25                             ; void *instance
| || || |   0x100003c2c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| || || |   0x100003c30      mov   x0, x23                             ; void *instance
| || || |   0x100003c34      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| || || |   0x100003c38      mov   x0, x27                             ; void *instance
| || || |   0x100003c3c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| || || |   0x100003c40      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
| || || |   0x100003c44      add   x21, x21, 0x2a0                     ; 0x10000c2a0
| || || |                                                              ; reloc.__CFConstantStringClassReference.10000c2a0
| || || |   0x100003c48      mov   x0, x19
| || || |   0x100003c4c      mov   x2, x21
| || || |   0x100003c50      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| || || |   0x100003c54      bl    sym.imp.objc_claimAutoreleasedReturnValue
| || || |   0x100003c58      mov   x27, x0
| || || |   0x100003c5c      mov   x0, x20
| || || |   0x100003c60      mov   x2, x21
| || || |   0x100003c64      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| || || |   0x100003c68      bl    sym.imp.objc_claimAutoreleasedReturnValue
| || || |   0x100003c6c      mov   x21, x0
| || ||,==< 0x100003c70      cbz   x27, 0x100003c78
| ||,=====< 0x100003c74      cbz   x21, 0x100003fd0
| =====`--> 0x100003c78      cbz   x27, 0x100003dac
| ||||| |   0x100003c7c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| ||||| |   0x100003c80      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ||||| |   0x100003c84      bl    sym.imp.objc_opt_class
| ||||| |   0x100003c88      mov   x1, x0
| ||||| |   0x100003c8c      mov   x0, x27
| ||||| |   0x100003c90      bl    sym.imp.objc_opt_isKindOfClass
| |||||,==< 0x100003c94      tbnz  w0, 0, 0x100003cb4
| |||||||   0x100003c98      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||||||   0x100003c9c      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||||||   0x100003ca0      bl    sym.imp.objc_opt_class
| |||||||   0x100003ca4      mov   x1, x0
| |||||||   0x100003ca8      mov   x0, x27
| |||||||   0x100003cac      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100003cb0      tbz   w0, 0, 0x100003fd0
| |||||`--> 0x100003cb4      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ||||| |   0x100003cb8      bl    sym.imp.objc_opt_class
| ||||| |   0x100003cbc      mov   x1, x0
| ||||| |   0x100003cc0      mov   x0, x27
| ||||| |   0x100003cc4      bl    sym.imp.objc_opt_isKindOfClass
| ||||| |   0x100003cc8      mov   x23, x0
| ||||| |   0x100003ccc      mov   x0, x27                             ; void *instance
| ||||| |   0x100003cd0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ||||| |   0x100003cd4      mov   x24, x0
| |||||,==< 0x100003cd8      tbz   w23, 0, 0x100003db8
| |||||||   0x100003cdc      movi  v0.2d, 0000000000000000
| |||||||   0x100003ce0      stp   q0, q0, [var_2e0h + 0x10]
| |||||||   0x100003ce4      stp   q0, q0, [var_2f0h]
| |||||||   0x100003ce8      add   x2, var_2f0h
| |||||||   0x100003cec      add   x3, var_170h
| |||||||   0x100003cf0      mov   x0, x24
| |||||||   0x100003cf4      mov   w4, 0x10
| |||||||   0x100003cf8      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x100003cfc      cbz   x0, 0x10000417c
| |||||||   0x100003d00      mov   x23, x0
| |||||||   0x100003d04      str   x27, [var_378h]
| |||||||   0x100003d08      mov   x25, 0
| |||||||   0x100003d0c      mov   w27, 0
| |||||||   0x100003d10      ldr   x8, [var_2e0h]                      ; [0xa0:4]=-1 ; 160
| |||||||   0x100003d14      ldr   x28, [x8]
| --------> 0x100003d18      mov   x22, 0
| |||||||   0x100003d1c      mov   x26, x25
| --------> 0x100003d20      ldr   x8, [var_2e0h]                      ; [0xa0:4]=-1 ; 160
| |||||||   0x100003d24      ldr   x8, [x8]
| |||||||   0x100003d28      cmp   x8, x28
| ========< 0x100003d2c      b.eq  0x100003d38
| |||||||   0x100003d30      mov   x0, x24                             ; void *instance
| |||||||   0x100003d34      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100003d38      ldr   x8, [var_2e8h]                      ; [0x98:4]=-1 ; 152
| |||||||   0x100003d3c      ldr   x0, [x8, x22, lsl 3]                ; void *instance
| |||||||   0x100003d40      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100003d44      mov   x25, x0
| |||||||   0x100003d48      mov   x0, x26                             ; void *instance
| |||||||   0x100003d4c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003d50      mov   x1, x25                             ; int64_t arg3
| |||||||   0x100003d54      mov   x2, x21
| |||||||   0x100003d58      bl    sym.func.100001fa0
| |||||||   0x100003d5c      orr   w27, w27, w0
| |||||||   0x100003d60      add   x22, x22, 1
| |||||||   0x100003d64      mov   x26, x25
| |||||||   0x100003d68      subs  x23, x23, 1
| ========< 0x100003d6c      b.ne  0x100003d20
| |||||||   0x100003d70      add   x2, var_2f0h
| |||||||   0x100003d74      add   x3, var_170h
| |||||||   0x100003d78      mov   x0, x24
| |||||||   0x100003d7c      mov   w4, 0x10
| |||||||   0x100003d80      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x100003d84      mov   x23, x0
| ========< 0x100003d88      cbnz  x0, 0x100003d18
| |||||||   0x100003d8c      mov   x0, x25                             ; void *instance
| |||||||   0x100003d90      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003d94      mov   x25, 0
| ========< 0x100003d98      tbz   w27, 0, 0x100004180
| |||||||   0x100003d9c      mov   x23, x24
| |||||||   0x100003da0      mov   x24, x25
| |||||||   0x100003da4      ldr   x27, [var_378h]                     ; [0x8:4]=-1 ; 8
| ========< 0x100003da8      b     0x100003dcc
| --------> 0x100003dac      mov   x23, 0
| |||||||   0x100003db0      mov   x24, 0
| ========< 0x100003db4      b     0x100003dcc
| |||||`--> 0x100003db8      mov   x1, x24                             ; int64_t arg3
| ||||| |   0x100003dbc      mov   x2, x21
| ||||| |   0x100003dc0      bl    sym.func.100001fa0
| ||||| |   0x100003dc4      mov   x23, 0
| |||||,==< 0x100003dc8      cbz   w0, 0x1000041b8
| |||||||   ; CODE XREFS from sym.func.100003a18 @ 0x100003da8, 0x100003db4
| --------> 0x100003dcc      mov   x0, x21                             ; void *instance
| |||||||   0x100003dd0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003dd4      mov   x0, x24                             ; void *instance
| |||||||   0x100003dd8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003ddc      mov   x0, x23                             ; void *instance
| |||||||   0x100003de0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003de4      mov   x0, x27                             ; void *instance
| |||||||   0x100003de8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003dec      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||||   0x100003df0      add   x21, x21, 0x2c0                     ; 0x10000c2c0
| |||||||                                                              ; reloc.__CFConstantStringClassReference.10000c2c0
| |||||||   0x100003df4      mov   x0, x19
| |||||||   0x100003df8      mov   x2, x21
| |||||||   0x100003dfc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||||   0x100003e00      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||||   0x100003e04      mov   x27, x0
| |||||||   0x100003e08      mov   x0, x20
| |||||||   0x100003e0c      mov   x2, x21
| |||||||   0x100003e10      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||||   0x100003e14      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||||   0x100003e18      mov   x21, x0
| ========< 0x100003e1c      cbz   x27, 0x100003e24
| ========< 0x100003e20      cbz   x21, 0x100003fd0
| --------> 0x100003e24      cbz   x27, 0x100003f58
| |||||||   0x100003e28      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||||   0x100003e2c      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |||||||   0x100003e30      bl    sym.imp.objc_opt_class
| |||||||   0x100003e34      mov   x1, x0
| |||||||   0x100003e38      mov   x0, x27
| |||||||   0x100003e3c      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100003e40      tbnz  w0, 0, 0x100003e60
| |||||||   0x100003e44      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| |||||||   0x100003e48      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |||||||   0x100003e4c      bl    sym.imp.objc_opt_class
| |||||||   0x100003e50      mov   x1, x0
| |||||||   0x100003e54      mov   x0, x27
| |||||||   0x100003e58      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100003e5c      tbz   w0, 0, 0x100003fd0
| --------> 0x100003e60      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |||||||   0x100003e64      bl    sym.imp.objc_opt_class
| |||||||   0x100003e68      mov   x1, x0
| |||||||   0x100003e6c      mov   x0, x27
| |||||||   0x100003e70      bl    sym.imp.objc_opt_isKindOfClass
| |||||||   0x100003e74      mov   x23, x0
| |||||||   0x100003e78      mov   x0, x27                             ; void *instance
| |||||||   0x100003e7c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100003e80      mov   x24, x0
| ========< 0x100003e84      tbz   w23, 0, 0x100003f64
| |||||||   0x100003e88      movi  v0.2d, 0000000000000000
| |||||||   0x100003e8c      stp   q0, q0, [var_320h + 0x10]
| |||||||   0x100003e90      stp   q0, q0, [var_330h]
| |||||||   0x100003e94      add   x2, var_330h
| |||||||   0x100003e98      add   x3, var_1f0h
| |||||||   0x100003e9c      mov   x0, x24
| |||||||   0x100003ea0      mov   w4, 0x10
| |||||||   0x100003ea4      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x100003ea8      cbz   x0, 0x10000417c
| |||||||   0x100003eac      mov   x23, x0
| |||||||   0x100003eb0      str   x27, [var_378h]
| |||||||   0x100003eb4      mov   x25, 0
| |||||||   0x100003eb8      mov   w27, 0
| |||||||   0x100003ebc      ldr   x8, [var_320h]                      ; [0x60:4]=-1 ; 96
| |||||||   0x100003ec0      ldr   x28, [x8]
| --------> 0x100003ec4      mov   x22, 0
| |||||||   0x100003ec8      mov   x26, x25
| --------> 0x100003ecc      ldr   x8, [var_320h]                      ; [0x60:4]=-1 ; 96
| |||||||   0x100003ed0      ldr   x8, [x8]
| |||||||   0x100003ed4      cmp   x8, x28
| ========< 0x100003ed8      b.eq  0x100003ee4
| |||||||   0x100003edc      mov   x0, x24                             ; void *instance
| |||||||   0x100003ee0      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100003ee4      ldr   x8, [var_328h]                      ; [0x58:4]=-1 ; 88
| |||||||   0x100003ee8      ldr   x0, [x8, x22, lsl 3]                ; void *instance
| |||||||   0x100003eec      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100003ef0      mov   x25, x0
| |||||||   0x100003ef4      mov   x0, x26                             ; void *instance
| |||||||   0x100003ef8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003efc      mov   x1, x25                             ; int64_t arg3
| |||||||   0x100003f00      mov   x2, x21
| |||||||   0x100003f04      bl    sym.func.100001fa0
| |||||||   0x100003f08      orr   w27, w27, w0
| |||||||   0x100003f0c      add   x22, x22, 1
| |||||||   0x100003f10      mov   x26, x25
| |||||||   0x100003f14      subs  x23, x23, 1
| ========< 0x100003f18      b.ne  0x100003ecc
| |||||||   0x100003f1c      add   x2, var_330h
| |||||||   0x100003f20      add   x3, var_1f0h
| |||||||   0x100003f24      mov   x0, x24
| |||||||   0x100003f28      mov   w4, 0x10
| |||||||   0x100003f2c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x100003f30      mov   x23, x0
| ========< 0x100003f34      cbnz  x0, 0x100003ec4
| |||||||   0x100003f38      mov   x0, x25                             ; void *instance
| |||||||   0x100003f3c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003f40      mov   x25, 0
| ========< 0x100003f44      tbz   w27, 0, 0x100004180
| |||||||   0x100003f48      mov   x23, x24
| |||||||   0x100003f4c      mov   x24, x25
| |||||||   0x100003f50      ldr   x27, [var_378h]                     ; [0x8:4]=-1 ; 8
| ========< 0x100003f54      b     0x100003f78
| --------> 0x100003f58      mov   x23, 0
| |||||||   0x100003f5c      mov   x24, 0
| ========< 0x100003f60      b     0x100003f78
| --------> 0x100003f64      mov   x1, x24                             ; int64_t arg3
| |||||||   0x100003f68      mov   x2, x21
| |||||||   0x100003f6c      bl    sym.func.100001fa0
| |||||||   0x100003f70      mov   x23, 0
| ========< 0x100003f74      cbz   w0, 0x1000041b8
| |||||||   ; CODE XREFS from sym.func.100003a18 @ 0x100003f54, 0x100003f60
| --------> 0x100003f78      mov   x0, x21                             ; void *instance
| |||||||   0x100003f7c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003f80      mov   x0, x24                             ; void *instance
| |||||||   0x100003f84      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003f88      mov   x0, x23                             ; void *instance
| |||||||   0x100003f8c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003f90      mov   x0, x27                             ; void *instance
| |||||||   0x100003f94      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100003f98      adrp  x21, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||||   0x100003f9c      add   x21, x21, 0x2e0                     ; 0x10000c2e0
| |||||||                                                              ; reloc.__CFConstantStringClassReference.10000c2e0
| |||||||   0x100003fa0      mov   x0, x19
| |||||||   0x100003fa4      mov   x2, x21
| |||||||   0x100003fa8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||||   0x100003fac      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||||   0x100003fb0      mov   x27, x0
| |||||||   0x100003fb4      mov   x0, x20
| |||||||   0x100003fb8      mov   x2, x21
| |||||||   0x100003fbc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| |||||||   0x100003fc0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| |||||||   0x100003fc4      mov   x21, x0
| ========< 0x100003fc8      cbz   x27, 0x100004048
| ========< 0x100003fcc      cbnz  x21, 0x100004048
| -```----> 0x100003fd0      mov   x25, 0
| |   |||   0x100003fd4      mov   x23, 0
| |   |||   0x100003fd8      mov   w26, 0
| |   |||   ; CODE XREFS from sym.func.100003a18 @ 0x1000041b4, 0x1000041c4
| | ..----> 0x100003fdc      mov   x0, x21                             ; void *instance
| | ::|||   0x100003fe0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | ::|||   0x100003fe4      mov   x0, x25                             ; void *instance
| | ::|||   0x100003fe8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | ::|||   0x100003fec      mov   x0, x23                             ; void *instance
| | ::|||   0x100003ff0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | ::|||   0x100003ff4      mov   x0, x27                             ; void *instance
| | ::|||   0x100003ff8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | ::|||   ; CODE XREF from sym.func.100003a18 @ 0x100003bf8
| | ::||`-> 0x100003ffc      mov   x0, x20                             ; void *instance
| | ::||    0x100004000      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | ::||    0x100004004      mov   x0, x19                             ; void *instance
| | ::||    0x100004008      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| | ::||    0x10000400c      ldur  x8, [var_60h]
| | ::||    0x100004010      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
| | ::||    0x100004014      ldr   x9, [x9, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
| | ::||    0x100004018      ldr   x9, [x9]                            ; [0x10001c158:4]=0
| | ::||                                                               ; str.objc_stubs
| | ::||    0x10000401c      cmp   x9, x8
| | ::||,=< 0x100004020      b.ne  0x1000041c8
| | ::|||   0x100004024      mov   x0, x26
| | ::|||   0x100004028      add   sp, sp, 0x320
| | ::|||   0x10000402c      ldp   x29, x30, [var_10h]
| | ::|||   0x100004030      ldp   x20, x19, [var_20h]
| | ::|||   0x100004034      ldp   x22, x21, [var_30h]
| | ::|||   0x100004038      ldp   x24, x23, [var_40h]
| | ::|||   0x10000403c      ldp   x26, x25, [var_50h]
| | ::|||   0x100004040      ldp   x28, x27, [sp], 0x60
| | ::|||   0x100004044      retab
| -,======< 0x100004048      cbz   x27, 0x10000418c
| ||::|||   0x10000404c      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| ||::|||   0x100004050      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ||::|||   0x100004054      bl    sym.imp.objc_opt_class
| ||::|||   0x100004058      mov   x1, x0
| ||::|||   0x10000405c      mov   x0, x27
| ||::|||   0x100004060      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100004064      tbnz  w0, 0, 0x100004084
| ||::|||   0x100004068      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||::|||   0x10000406c      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||::|||   0x100004070      bl    sym.imp.objc_opt_class
| ||::|||   0x100004074      mov   x1, x0
| ||::|||   0x100004078      mov   x0, x27
| ||::|||   0x10000407c      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100004080      tbz   w0, 0, 0x100003fd0
| --------> 0x100004084      ldr   x0, [x22, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ||::|||   0x100004088      bl    sym.imp.objc_opt_class
| ||::|||   0x10000408c      mov   x1, x0
| ||::|||   0x100004090      mov   x0, x27
| ||::|||   0x100004094      bl    sym.imp.objc_opt_isKindOfClass
| ||::|||   0x100004098      mov   x23, x0
| ||::|||   0x10000409c      mov   x0, x27                             ; void *instance
| ||::|||   0x1000040a0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ||::|||   0x1000040a4      mov   x24, x0
| ========< 0x1000040a8      tbz   w23, 0, 0x100004198
| ||::|||   0x1000040ac      movi  v0.2d, 0000000000000000
| ||::|||   0x1000040b0      stp   q0, q0, [var_360h + 0x10]
| ||::|||   0x1000040b4      stp   q0, q0, [var_370h]
| ||::|||   0x1000040b8      add   x2, var_370h
| ||::|||   0x1000040bc      add   x3, var_270h
| ||::|||   0x1000040c0      mov   x0, x24
| ||::|||   0x1000040c4      mov   w4, 0x10
| ||::|||   0x1000040c8      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x1000040cc      cbz   x0, 0x10000417c
| ||::|||   0x1000040d0      mov   x23, x0
| ||::|||   0x1000040d4      str   x27, [var_378h]
| ||::|||   0x1000040d8      mov   x25, 0
| ||::|||   0x1000040dc      mov   w27, 0
| ||::|||   0x1000040e0      ldr   x8, [var_360h]                      ; [0x20:4]=-1 ; 32
| ||::|||   0x1000040e4      ldr   x28, [x8]
| --------> 0x1000040e8      mov   x22, 0
| ||::|||   0x1000040ec      mov   x26, x25
| --------> 0x1000040f0      ldr   x8, [var_360h]                      ; [0x20:4]=-1 ; 32
| ||::|||   0x1000040f4      ldr   x8, [x8]
| ||::|||   0x1000040f8      cmp   x8, x28
| ========< 0x1000040fc      b.eq  0x100004108
| ||::|||   0x100004100      mov   x0, x24                             ; void *instance
| ||::|||   0x100004104      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100004108      ldr   x8, [var_368h]                      ; [0x18:4]=-1 ; 24
| ||::|||   0x10000410c      ldr   x0, [x8, x22, lsl 3]                ; void *instance
| ||::|||   0x100004110      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ||::|||   0x100004114      mov   x25, x0
| ||::|||   0x100004118      mov   x0, x26                             ; void *instance
| ||::|||   0x10000411c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||::|||   0x100004120      mov   x1, x25                             ; int64_t arg3
| ||::|||   0x100004124      mov   x2, x21
| ||::|||   0x100004128      bl    sym.func.100001fa0
| ||::|||   0x10000412c      orr   w27, w27, w0
| ||::|||   0x100004130      add   x22, x22, 1
| ||::|||   0x100004134      mov   x26, x25
| ||::|||   0x100004138      subs  x23, x23, 1
| ========< 0x10000413c      b.ne  0x1000040f0
| ||::|||   0x100004140      add   x2, var_370h
| ||::|||   0x100004144      add   x3, var_270h
| ||::|||   0x100004148      mov   x0, x24
| ||::|||   0x10000414c      mov   w4, 0x10
| ||::|||   0x100004150      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ||::|||   0x100004154      mov   x23, x0
| ========< 0x100004158      cbnz  x0, 0x1000040e8
| ||::|||   0x10000415c      mov   x0, x25                             ; void *instance
| ||::|||   0x100004160      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||::|||   0x100004164      mov   x25, 0
| ========< 0x100004168      tbz   w27, 0, 0x100004180
| ||::|||   0x10000416c      mov   x23, x24
| ||::|||   0x100004170      mov   x24, x25
| ||::|||   0x100004174      ldr   x27, [var_378h]                     ; [0x8:4]=-1 ; 8
| ========< 0x100004178      b     0x1000041ac
| `-------> 0x10000417c      mov   x25, 0
| --------> 0x100004180      mov   w26, 0
|  |::|||   0x100004184      mov   x23, x24
| ,=======< 0x100004188      b     0x1000041c0
| |`------> 0x10000418c      mov   x23, 0
| | ::|||   0x100004190      mov   x24, 0
| |,======< 0x100004194      b     0x1000041ac
| --------> 0x100004198      mov   x1, x24                             ; int64_t arg3
| ||::|||   0x10000419c      mov   x2, x21
| ||::|||   0x1000041a0      bl    sym.func.100001fa0
| ||::|||   0x1000041a4      mov   x23, 0
| ========< 0x1000041a8      cbz   w0, 0x1000041b8
| ||::|||   ; CODE XREFS from sym.func.100003a18 @ 0x100004178, 0x100004194
| -`------> 0x1000041ac      mov   w26, 1
| | ::|||   0x1000041b0      mov   x25, x24
| | `=====< 0x1000041b4      b     0x100003fdc
| ----``--> 0x1000041b8      mov   w26, 0
| |  :  |   0x1000041bc      mov   x25, x24
| |  :  |   ; CODE XREF from sym.func.100003a18 @ 0x100004188
| `-------> 0x1000041c0      mov   x27, x24
|    `====< 0x1000041c4      b     0x100003fdc
\       `-> 0x1000041c8      bl    sym.imp.__stack_chk_fail            ; void __stack_chk_fail(void)
