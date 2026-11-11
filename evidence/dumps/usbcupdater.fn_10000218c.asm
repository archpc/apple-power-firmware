[2K            ; CALL XREF from sym.func.100003a18 @ 0x100003a74
            ; CALL XREF from sym.func.1000041cc @ 0x100004410
/ sym.func.10000218c(void *instance, int64_t arg2, int64_t arg3);
|           ; arg void *instance @ x0
|           ; arg int64_t arg2 @ x1
|           ; arg int64_t arg3 @ x2
|           ; var int64_t var_508h @ stack - 0x508
|           ; var int64_t var_500h @ stack - 0x500
|           ; var int64_t var_4f8h @ stack - 0x4f8
|           ; var int64_t var_4f0h @ stack - 0x4f0
|           ; var int64_t var_4e8h @ stack - 0x4e8
|           ; var int64_t var_4e0h @ stack - 0x4e0
|           ; var int64_t var_4b0h @ stack - 0x4b0
|           ; var int64_t var_4a8h @ stack - 0x4a8
|           ; var int64_t var_4a0h @ stack - 0x4a0
|           ; var int64_t var_470h @ stack - 0x470
|           ; var int64_t var_468h @ stack - 0x468
|           ; var int64_t var_460h @ stack - 0x460
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
|           0x10000218c      pacibsp
|           0x100002190      stp   x28, x27, [var_60h]!
|           0x100002194      stp   x26, x25, [var_50h]
|           0x100002198      stp   x24, x23, [var_40h]
|           0x10000219c      stp   x22, x21, [var_30h]
|           0x1000021a0      stp   x20, x19, [var_20h]
|           0x1000021a4      stp   x29, x30, [var_10h]
|           0x1000021a8      add   x29, sp, 0x50
|           0x1000021ac      sub   sp, sp, 0x4b0
|           0x1000021b0      mov   x25, x2                             ; arg3
|           0x1000021b4      mov   x20, x1                             ; arg2
|           0x1000021b8      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x1000021bc      ldr   x8, [x8, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
|           0x1000021c0      ldr   x8, [x8]                            ; [0x10001c158:4]=0
|                                                                      ; str.objc_stubs
|           0x1000021c4      stur  x8, [var_60h]
|           0x1000021c8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x1000021cc      mov   x28, x0
|           0x1000021d0      mov   x0, x20                             ; void *instance
|           0x1000021d4      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|           0x1000021d8      mov   x20, x0
|           0x1000021dc      mov   x0, x28                             ; void *instance
|           0x1000021e0      mov   x1, x20                             ; int64_t arg2
|           0x1000021e4      bl    sym.func.100001ad8
|       ,=< 0x1000021e8      cbz   w0, 0x100002254
|       |   0x1000021ec      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|       |   0x1000021f0      add   x22, x22, 0x180                     ; 0x10000c180
|       |                                                              ; reloc.__CFConstantStringClassReference.10000c180
|       |   0x1000021f4      mov   x0, x28
|       |   0x1000021f8      mov   x2, x22
|       |   0x1000021fc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|       |   0x100002200      bl    sym.imp.objc_claimAutoreleasedReturnValue
|       |   0x100002204      mov   x21, x0
|       |   0x100002208      mov   x0, x20
|       |   0x10000220c      mov   x2, x22
|       |   0x100002210      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|       |   0x100002214      bl    sym.imp.objc_claimAutoreleasedReturnValue
|       |   0x100002218      mov   x22, x0
|      ,==< 0x10000221c      cbz   x21, 0x1000022a4
|     ,===< 0x100002220      cbnz  x22, 0x1000022a4
|     |||   ; CODE XREF from sym.func.10000218c @ 0x1000029f8
| ....----> 0x100002224      mov   x24, 0
| ::::|||   0x100002228      mov   x23, 0
| ::::|||   0x10000222c      mov   w25, 0
| ::::|||   ; XREFS: CODE 0x100002644  CODE 0x100002658  CODE 0x100002808
| ::::|||   ; XREFS: CODE 0x1000029b8  CODE 0x1000029cc  CODE 0x100002a90
| --------> 0x100002230      mov   x0, x22                             ; void *instance
| ::::|||   0x100002234      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   ; CODE XREF from sym.func.10000218c @ 0x100002624
| --------> 0x100002238      mov   x0, x24                             ; void *instance
| ::::|||   0x10000223c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x100002240      mov   x0, x23                             ; void *instance
| ::::|||   0x100002244      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x100002248      mov   x0, x21                             ; void *instance
| ::::|||   0x10000224c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ========< 0x100002250      b     0x100002258
| ::::||`-> 0x100002254      mov   w25, 0
| ::::||    ; CODE XREF from sym.func.10000218c @ 0x100002250
| --------> 0x100002258      mov   x0, x20                             ; void *instance
| ::::||    0x10000225c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::||    0x100002260      mov   x0, x28                             ; void *instance
| ::::||    0x100002264      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::||    0x100002268      ldur  x8, [var_60h]
| ::::||    0x10000226c      adrp  x9, section.7.__DATA_CONST.__const  ; 0x10000c000
| ::::||    0x100002270      ldr   x9, [x9, 0xbf0]                     ; [0x10000cbf0:4]=0x1c158 ; "X\xc1\U00000001"
| ::::||    0x100002274      ldr   x9, [x9]                            ; [0x10001c158:4]=0
| ::::||                                                               ; str.objc_stubs
| ::::||    0x100002278      cmp   x9, x8
| ::::||,=< 0x10000227c      b.ne  0x100002e00
| ::::|||   0x100002280      mov   x0, x25
| ::::|||   0x100002284      add   sp, sp, 0x4b0
| ::::|||   0x100002288      ldp   x29, x30, [var_10h]
| ::::|||   0x10000228c      ldp   x20, x19, [var_20h]
| ::::|||   0x100002290      ldp   x22, x21, [var_30h]
| ::::|||   0x100002294      ldp   x24, x23, [var_40h]
| ::::|||   0x100002298      ldp   x26, x25, [var_50h]
| ::::|||   0x10000229c      ldp   x28, x27, [sp], 0x60
| ::::|||   0x1000022a0      retab
| ====``--> 0x1000022a4      cbz   x21, 0x1000023d8
| ::::  |   0x1000022a8      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| ::::  |   0x1000022ac      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ::::  |   0x1000022b0      bl    sym.imp.objc_opt_class
| ::::  |   0x1000022b4      mov   x1, x0
| ::::  |   0x1000022b8      mov   x0, x21
| ::::  |   0x1000022bc      bl    sym.imp.objc_opt_isKindOfClass
| :::: ,==< 0x1000022c0      tbnz  w0, 0, 0x1000022e0
| :::: ||   0x1000022c4      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| :::: ||   0x1000022c8      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| :::: ||   0x1000022cc      bl    sym.imp.objc_opt_class
| :::: ||   0x1000022d0      mov   x1, x0
| :::: ||   0x1000022d4      mov   x0, x21
| :::: ||   0x1000022d8      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000022dc      tbz   w0, 0, 0x100002224
| :::: `--> 0x1000022e0      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ::::  |   0x1000022e4      bl    sym.imp.objc_opt_class
| ::::  |   0x1000022e8      mov   x1, x0
| ::::  |   0x1000022ec      mov   x0, x21
| ::::  |   0x1000022f0      bl    sym.imp.objc_opt_isKindOfClass
| ::::  |   0x1000022f4      mov   x23, x0
| ::::  |   0x1000022f8      mov   x0, x21                             ; void *instance
| ::::  |   0x1000022fc      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ::::  |   0x100002300      mov   x26, x0
| :::: ,==< 0x100002304      tbz   w23, 0, 0x1000023e4
| :::: ||   0x100002308      movi  v0.2d, 0000000000000000
| :::: ||   0x10000230c      stp   q0, q0, [var_3a0h + 0x10]
| :::: ||   0x100002310      stp   q0, q0, [var_3b0h]
| :::: ||   0x100002314      add   x2, var_3b0h
| :::: ||   0x100002318      sub   x3, var_10h + 0xf0
| :::: ||   0x10000231c      mov   x0, x26
| :::: ||   0x100002320      mov   w4, 0x10
| :::: ||   0x100002324      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ::::,===< 0x100002328      cbz   x0, 0x100002634
| ::::|||   0x10000232c      mov   x23, x0
| ::::|||   0x100002330      stp   x28, x20, [var_500h]
| ::::|||   0x100002334      mov   w28, 0
| ::::|||   0x100002338      mov   x24, 0
| ::::|||   0x10000233c      ldr   x8, [var_3a0h]                      ; [0x170:4]=-1 ; 368
| ::::|||   0x100002340      ldr   x20, [x8]
| --------> 0x100002344      mov   x19, 0
| ::::|||   0x100002348      mov   x27, x24
| --------> 0x10000234c      ldr   x8, [var_3a0h]                      ; [0x170:4]=-1 ; 368
| ::::|||   0x100002350      ldr   x8, [x8]
| ::::|||   0x100002354      cmp   x8, x20
| ========< 0x100002358      b.eq  0x100002364
| ::::|||   0x10000235c      mov   x0, x26                             ; void *instance
| ::::|||   0x100002360      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100002364      ldr   x8, [var_3a8h]                      ; [0x168:4]=-1 ; 360
| ::::|||   0x100002368      ldr   x0, [x8, x19, lsl 3]                ; void *instance
| ::::|||   0x10000236c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ::::|||   0x100002370      mov   x24, x0
| ::::|||   0x100002374      mov   x0, x27                             ; void *instance
| ::::|||   0x100002378      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x10000237c      mov   x1, x24                             ; int64_t arg3
| ::::|||   0x100002380      mov   x2, x22
| ::::|||   0x100002384      bl    sym.func.100001fa0
| ::::|||   0x100002388      orr   w28, w28, w0
| ::::|||   0x10000238c      add   x19, x19, 1
| ::::|||   0x100002390      mov   x27, x24
| ::::|||   0x100002394      subs  x23, x23, 1
| ========< 0x100002398      b.ne  0x10000234c
| ::::|||   0x10000239c      add   x2, var_3b0h
| ::::|||   0x1000023a0      sub   x3, var_10h + 0xf0
| ::::|||   0x1000023a4      mov   x0, x26
| ::::|||   0x1000023a8      mov   w4, 0x10
| ::::|||   0x1000023ac      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ::::|||   0x1000023b0      mov   x23, x0
| ========< 0x1000023b4      cbnz  x0, 0x100002344
| ::::|||   0x1000023b8      mov   x0, x24                             ; void *instance
| ::::|||   0x1000023bc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x1000023c0      mov   x24, 0
| ::::|||   0x1000023c4      ldr   x20, [var_4f8h]                     ; [0x18:4]=-1 ; 24
| ========< 0x1000023c8      tbz   w28, 0, 0x100002648
| ::::|||   0x1000023cc      mov   x23, x26
| ::::|||   0x1000023d0      ldr   x28, [var_500h]                     ; [0x10:4]=-1 ; 16
| ========< 0x1000023d4      b     0x1000023fc
| --------> 0x1000023d8      mov   x24, 0
| ::::|||   0x1000023dc      mov   x23, 0
| ========< 0x1000023e0      b     0x1000023fc
| ::::|`--> 0x1000023e4      mov   x1, x26                             ; int64_t arg3
| ::::| |   0x1000023e8      mov   x2, x22
| ::::| |   0x1000023ec      bl    sym.func.100001fa0
| ::::| |   0x1000023f0      mov   x23, 0
| ::::|,==< 0x1000023f4      cbz   w0, 0x100002628
| ::::|||   0x1000023f8      mov   x24, x26
| ::::|||   ; CODE XREFS from sym.func.10000218c @ 0x1000023d4, 0x1000023e0
| --------> 0x1000023fc      mov   x0, x22                             ; void *instance
| ::::|||   0x100002400      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x100002404      mov   x0, x24                             ; void *instance
| ::::|||   0x100002408      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x10000240c      mov   x0, x23                             ; void *instance
| ::::|||   0x100002410      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x100002414      mov   x0, x21                             ; void *instance
| ::::|||   0x100002418      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x10000241c      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| ::::|||   0x100002420      add   x2, x2, 0x540                       ; 0x10000c540
| ::::|||                                                              ; reloc.__CFConstantStringClassReference.10000c540
| ::::|||   0x100002424      mov   x0, x28
| ::::|||   0x100002428      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| ::::|||   0x10000242c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::::|||   0x100002430      mov   x21, x0
| ::::|||   0x100002434      adrp  x2, section.7.__DATA_CONST.__const  ; 0x10000c000
| ::::|||   0x100002438      add   x2, x2, 0x560                       ; 0x10000c560
| ::::|||                                                              ; reloc.__CFConstantStringClassReference.10000c560
| ::::|||   0x10000243c      mov   x0, x28
| ::::|||   0x100002440      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| ::::|||   0x100002444      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::::|||   0x100002448      mov   x23, x0
| ::::|||   0x10000244c      adrp  x27, section.7.__DATA_CONST.__const ; 0x10000c000
| ::::|||   0x100002450      ldr   x0, [x27, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ::::|||   0x100002454      mov   w2, w25
| ::::|||   0x100002458      bl    stub.objc_msgSend_numberWithInteger: ;  stub.objc_msgSend_numberWithInteger:(void)
| ::::|||   0x10000245c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::::|||   0x100002460      mov   x24, x0
| ========< 0x100002464      cbz   x21, 0x10000247c
| ::::|||   0x100002468      mov   x0, x21
| ::::|||   0x10000246c      mov   x2, x24
| ::::|||   0x100002470      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ::::|||   0x100002474      cmp   x0, 1
| ========< 0x100002478      b.eq  0x100002620
| --------> 0x10000247c      cbz   x23, 0x100002494
| ::::|||   0x100002480      mov   x0, x23
| ::::|||   0x100002484      mov   x2, x24
| ::::|||   0x100002488      bl    stub.objc_msgSend_compare:          ;  stub.objc_msgSend_compare:(void)
| ::::|||   0x10000248c      cmn   x0, 1
| ========< 0x100002490      b.eq  0x100002620
| --------> 0x100002494      mov   x0, x24                             ; void *instance
| ::::|||   0x100002498      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x10000249c      mov   x0, x23                             ; void *instance
| ::::|||   0x1000024a0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x1000024a4      mov   x0, x21                             ; void *instance
| ::::|||   0x1000024a8      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::::|||   0x1000024ac      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
| ::::|||   0x1000024b0      add   x22, x22, 0x3e0                     ; 0x10000c3e0
| ::::|||                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| ::::|||   0x1000024b4      mov   x0, x28
| ::::|||   0x1000024b8      mov   x2, x22
| ::::|||   0x1000024bc      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| ::::|||   0x1000024c0      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::::|||   0x1000024c4      mov   x21, x0
| ::::|||   0x1000024c8      mov   x0, x20
| ::::|||   0x1000024cc      mov   x2, x22
| ::::|||   0x1000024d0      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
| ::::|||   0x1000024d4      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ::::|||   0x1000024d8      mov   x22, x0
| ::::|||   0x1000024dc      mov   w25, 0
| ::::|||   0x1000024e0      mov   x24, 0
| ========< 0x1000024e4      cbz   x21, 0x100002804
| ========< 0x1000024e8      cbz   x22, 0x100002804
| ::::|||   0x1000024ec      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| ::::|||   0x1000024f0      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ::::|||   0x1000024f4      bl    sym.imp.objc_opt_class
| ::::|||   0x1000024f8      mov   x1, x0
| ::::|||   0x1000024fc      mov   x0, x21
| ::::|||   0x100002500      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100002504      tbnz  w0, 0, 0x100002520
| ::::|||   0x100002508      ldr   x0, [x27, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ::::|||   0x10000250c      bl    sym.imp.objc_opt_class
| ::::|||   0x100002510      mov   x1, x0
| ::::|||   0x100002514      mov   x0, x21
| ::::|||   0x100002518      bl    sym.imp.objc_opt_isKindOfClass
| `=======< 0x10000251c      tbz   w0, 0, 0x100002224
| --------> 0x100002520      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  :::|||   0x100002524      bl    sym.imp.objc_opt_class
|  :::|||   0x100002528      mov   x1, x0
|  :::|||   0x10000252c      mov   x0, x21
|  :::|||   0x100002530      bl    sym.imp.objc_opt_isKindOfClass
|  :::|||   0x100002534      mov   x23, x0
|  :::|||   0x100002538      mov   x0, x21                             ; void *instance
|  :::|||   0x10000253c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  :::|||   0x100002540      mov   x21, x0
| ,=======< 0x100002544      tbz   w23, 0, 0x10000265c
| |:::|||   0x100002548      movi  v0.2d, 0000000000000000
| |:::|||   0x10000254c      stp   q0, q0, [var_3e0h + 0x10]
| |:::|||   0x100002550      stp   q0, q0, [var_3f0h]
| |:::|||   0x100002554      add   x2, var_3f0h
| |:::|||   0x100002558      add   x3, var_170h
| |:::|||   0x10000255c      mov   x0, x21
| |:::|||   0x100002560      mov   w4, 0x10
| |:::|||   0x100002564      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x100002568      cbz   x0, 0x1000029ac
| |:::|||   0x10000256c      mov   x23, x0
| |:::|||   0x100002570      str   x20, [var_4f8h]
| |:::|||   0x100002574      mov   x26, x28
| |:::|||   0x100002578      mov   w28, 0
| |:::|||   0x10000257c      mov   x24, 0
| |:::|||   0x100002580      ldr   x8, [var_3e0h]                      ; [0x130:4]=-1 ; 304
| |:::|||   0x100002584      ldr   x20, [x8]
| --------> 0x100002588      mov   x19, 0
| |:::|||   0x10000258c      mov   x25, x24
| --------> 0x100002590      ldr   x8, [var_3e0h]                      ; [0x130:4]=-1 ; 304
| |:::|||   0x100002594      ldr   x8, [x8]
| |:::|||   0x100002598      cmp   x8, x20
| ========< 0x10000259c      b.eq  0x1000025a8
| |:::|||   0x1000025a0      mov   x0, x21                             ; void *instance
| |:::|||   0x1000025a4      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x1000025a8      ldr   x8, [var_3e8h]                      ; [0x128:4]=-1 ; 296
| |:::|||   0x1000025ac      ldr   x0, [x8, x19, lsl 3]                ; void *instance
| |:::|||   0x1000025b0      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |:::|||   0x1000025b4      mov   x24, x0
| |:::|||   0x1000025b8      mov   x0, x25                             ; void *instance
| |:::|||   0x1000025bc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |:::|||   0x1000025c0      mov   x1, x24                             ; int64_t arg3
| |:::|||   0x1000025c4      mov   x2, x22
| |:::|||   0x1000025c8      bl    sym.func.100001fa0
| |:::|||   0x1000025cc      orr   w28, w28, w0
| |:::|||   0x1000025d0      add   x19, x19, 1
| |:::|||   0x1000025d4      mov   x25, x24
| |:::|||   0x1000025d8      subs  x23, x23, 1
| ========< 0x1000025dc      b.ne  0x100002590
| |:::|||   0x1000025e0      add   x2, var_3f0h
| |:::|||   0x1000025e4      add   x3, var_170h
| |:::|||   0x1000025e8      mov   x0, x21
| |:::|||   0x1000025ec      mov   w4, 0x10
| |:::|||   0x1000025f0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |:::|||   0x1000025f4      mov   x23, x0
| ========< 0x1000025f8      cbnz  x0, 0x100002588
| |:::|||   0x1000025fc      mov   x0, x24                             ; void *instance
| |:::|||   0x100002600      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |:::|||   0x100002604      mov   x24, 0
| ========< 0x100002608      tbz   w28, 0, 0x1000029bc
| |:::|||   0x10000260c      mov   x23, x21
| |:::|||   0x100002610      mov   x28, x26
| |:::|||   0x100002614      ldr   x20, [var_4f8h]                     ; [0x18:4]=-1 ; 24
| |:::|||   0x100002618      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| ========< 0x10000261c      b     0x100002674
| --------> 0x100002620      mov   w25, 0
| ========< 0x100002624      b     0x100002238
| |:::|`--> 0x100002628      mov   w25, 0
| |:::| |   0x10000262c      mov   x24, x26
| |:::|,==< 0x100002630      b     0x100002640
| |:::`---> 0x100002634      mov   x24, 0
| |::: ||   0x100002638      mov   w25, 0
| |::: ||   0x10000263c      mov   x23, x26
| |::: ||   ; CODE XREF from sym.func.10000218c @ 0x100002630
| |::: `--> 0x100002640      mov   x21, x26
| ========< 0x100002644      b     0x100002230
| --------> 0x100002648      mov   w25, 0
| |:::  |   0x10000264c      mov   x23, x26
| |:::  |   0x100002650      mov   x21, x26
| |:::  |   0x100002654      ldr   x28, [var_500h]                     ; [0x10:4]=-1 ; 16
| ========< 0x100002658      b     0x100002230
| `-------> 0x10000265c      mov   x1, x21                             ; int64_t arg3
|  :::  |   0x100002660      mov   x2, x22
|  :::  |   0x100002664      bl    sym.func.100001fa0
|  :::  |   0x100002668      mov   x23, 0
|  ::: ,==< 0x10000266c      cbz   w0, 0x100002a88
|  ::: ||   0x100002670      mov   x24, x21
|  ::: ||   ; CODE XREF from sym.func.10000218c @ 0x10000261c
| --------> 0x100002674      mov   x0, x22                             ; void *instance
|  ::: ||   0x100002678      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ::: ||   0x10000267c      mov   x0, x24                             ; void *instance
|  ::: ||   0x100002680      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ::: ||   0x100002684      mov   x0, x23                             ; void *instance
|  ::: ||   0x100002688      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ::: ||   0x10000268c      mov   x0, x21                             ; void *instance
|  ::: ||   0x100002690      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  ::: ||   0x100002694      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|  ::: ||   0x100002698      add   x22, x22, 0x400                     ; 0x10000c400
|  ::: ||                                                              ; reloc.__CFConstantStringClassReference.10000c400
|  ::: ||   0x10000269c      mov   x0, x28
|  ::: ||   0x1000026a0      mov   x2, x22
|  ::: ||   0x1000026a4      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  ::: ||   0x1000026a8      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  ::: ||   0x1000026ac      mov   x21, x0
|  ::: ||   0x1000026b0      mov   x0, x20
|  ::: ||   0x1000026b4      mov   x2, x22
|  ::: ||   0x1000026b8      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  ::: ||   0x1000026bc      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  ::: ||   0x1000026c0      mov   x22, x0
|  ::: ||   0x1000026c4      mov   w25, 0
|  ::: ||   0x1000026c8      mov   x24, 0
|  :::,===< 0x1000026cc      cbz   x21, 0x100002804
| ,=======< 0x1000026d0      cbz   x22, 0x100002804
| |:::|||   0x1000026d4      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| |:::|||   0x1000026d8      bl    sym.imp.objc_opt_class
| |:::|||   0x1000026dc      mov   x1, x0
| |:::|||   0x1000026e0      mov   x0, x21
| |:::|||   0x1000026e4      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x1000026e8      tbnz  w0, 0, 0x100002704
| |:::|||   0x1000026ec      ldr   x0, [x27, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| |:::|||   0x1000026f0      bl    sym.imp.objc_opt_class
| |:::|||   0x1000026f4      mov   x1, x0
| |:::|||   0x1000026f8      mov   x0, x21
| |:::|||   0x1000026fc      bl    sym.imp.objc_opt_isKindOfClass
| |`======< 0x100002700      tbz   w0, 0, 0x100002224
| --------> 0x100002704      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| | ::|||   0x100002708      bl    sym.imp.objc_opt_class
| | ::|||   0x10000270c      mov   x1, x0
| | ::|||   0x100002710      mov   x0, x21
| | ::|||   0x100002714      bl    sym.imp.objc_opt_isKindOfClass
| | ::|||   0x100002718      mov   x23, x0
| | ::|||   0x10000271c      mov   x0, x21                             ; void *instance
| | ::|||   0x100002720      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| | ::|||   0x100002724      mov   x21, x0
| |,======< 0x100002728      tbz   w23, 0, 0x10000280c
| ||::|||   0x10000272c      movi  v0.2d, 0000000000000000
| ||::|||   0x100002730      stp   q0, q0, [var_420h + 0x10]
| ||::|||   0x100002734      stp   q0, q0, [var_430h]
| ||::|||   0x100002738      add   x2, var_430h
| ||::|||   0x10000273c      add   x3, var_1f0h
| ||::|||   0x100002740      mov   x0, x21
| ||::|||   0x100002744      mov   w4, 0x10
| ||::|||   0x100002748      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x10000274c      cbz   x0, 0x1000029ac
| ||::|||   0x100002750      mov   x23, x0
| ||::|||   0x100002754      str   x20, [var_4f8h]
| ||::|||   0x100002758      mov   x26, x28
| ||::|||   0x10000275c      mov   x24, 0
| ||::|||   0x100002760      mov   w28, 0
| ||::|||   0x100002764      ldr   x8, [var_420h]                      ; [0xf0:4]=-1 ; 240
| ||::|||   0x100002768      ldr   x20, [x8]
| --------> 0x10000276c      mov   x19, 0
| ||::|||   0x100002770      mov   x25, x24
| --------> 0x100002774      ldr   x8, [var_420h]                      ; [0xf0:4]=-1 ; 240
| ||::|||   0x100002778      ldr   x8, [x8]
| ||::|||   0x10000277c      cmp   x8, x20
| ========< 0x100002780      b.eq  0x10000278c
| ||::|||   0x100002784      mov   x0, x21                             ; void *instance
| ||::|||   0x100002788      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x10000278c      ldr   x8, [var_428h]                      ; [0xe8:4]=-1 ; 232
| ||::|||   0x100002790      ldr   x0, [x8, x19, lsl 3]                ; void *instance
| ||::|||   0x100002794      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ||::|||   0x100002798      mov   x24, x0
| ||::|||   0x10000279c      mov   x0, x25                             ; void *instance
| ||::|||   0x1000027a0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||::|||   0x1000027a4      mov   x1, x24                             ; int64_t arg3
| ||::|||   0x1000027a8      mov   x2, x22
| ||::|||   0x1000027ac      bl    sym.func.100001fa0
| ||::|||   0x1000027b0      orr   w28, w28, w0
| ||::|||   0x1000027b4      add   x19, x19, 1
| ||::|||   0x1000027b8      mov   x25, x24
| ||::|||   0x1000027bc      subs  x23, x23, 1
| ========< 0x1000027c0      b.ne  0x100002774
| ||::|||   0x1000027c4      add   x2, var_430h
| ||::|||   0x1000027c8      add   x3, var_1f0h
| ||::|||   0x1000027cc      mov   x0, x21
| ||::|||   0x1000027d0      mov   w4, 0x10
| ||::|||   0x1000027d4      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ||::|||   0x1000027d8      mov   x23, x0
| ========< 0x1000027dc      cbnz  x0, 0x10000276c
| ||::|||   0x1000027e0      mov   x0, x24                             ; void *instance
| ||::|||   0x1000027e4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||::|||   0x1000027e8      mov   x24, 0
| ========< 0x1000027ec      tbz   w28, 0, 0x1000029bc
| ||::|||   0x1000027f0      mov   x23, x21
| ||::|||   0x1000027f4      mov   x28, x26
| ||::|||   0x1000027f8      ldr   x20, [var_4f8h]                     ; [0x18:4]=-1 ; 24
| ||::|||   0x1000027fc      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| ========< 0x100002800      b     0x100002824
| `---`---> 0x100002804      mov   x23, x24
| ========< 0x100002808      b     0x100002230
|  `------> 0x10000280c      mov   x1, x21                             ; int64_t arg3
|   :: ||   0x100002810      mov   x2, x22
|   :: ||   0x100002814      bl    sym.func.100001fa0
|   :: ||   0x100002818      mov   x23, 0
|   ::,===< 0x10000281c      cbz   w0, 0x100002a88
|   ::|||   0x100002820      mov   x24, x21
|   ::|||   ; CODE XREF from sym.func.10000218c @ 0x100002800
| --------> 0x100002824      mov   x0, x22                             ; void *instance
|   ::|||   0x100002828      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   ::|||   0x10000282c      mov   x0, x24                             ; void *instance
|   ::|||   0x100002830      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   ::|||   0x100002834      mov   x0, x23                             ; void *instance
|   ::|||   0x100002838      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   ::|||   0x10000283c      mov   x0, x21                             ; void *instance
|   ::|||   0x100002840      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   ::|||   0x100002844      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|   ::|||   0x100002848      add   x22, x22, 0x420                     ; 0x10000c420
|   ::|||                                                              ; reloc.__CFConstantStringClassReference.10000c420
|   ::|||   0x10000284c      mov   x0, x28
|   ::|||   0x100002850      mov   x2, x22
|   ::|||   0x100002854      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|   ::|||   0x100002858      bl    sym.imp.objc_claimAutoreleasedReturnValue
|   ::|||   0x10000285c      mov   x21, x0
|   ::|||   0x100002860      mov   x0, x20
|   ::|||   0x100002864      mov   x2, x22
|   ::|||   0x100002868      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|   ::|||   0x10000286c      bl    sym.imp.objc_claimAutoreleasedReturnValue
|   ::|||   0x100002870      mov   x22, x0
|  ,======< 0x100002874      cbz   x21, 0x1000029d0
| ,=======< 0x100002878      cbz   x22, 0x1000029d0
| ||::|||   0x10000287c      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| ||::|||   0x100002880      bl    sym.imp.objc_opt_class
| ||::|||   0x100002884      mov   x1, x0
| ||::|||   0x100002888      mov   x0, x21
| ||::|||   0x10000288c      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100002890      tbnz  w0, 0, 0x1000028ac
| ||::|||   0x100002894      ldr   x0, [x27, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||::|||   0x100002898      bl    sym.imp.objc_opt_class
| ||::|||   0x10000289c      mov   x1, x0
| ||::|||   0x1000028a0      mov   x0, x21
| ||::|||   0x1000028a4      bl    sym.imp.objc_opt_isKindOfClass
| ||`=====< 0x1000028a8      tbz   w0, 0, 0x100002224
| --------> 0x1000028ac      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
| || :|||   0x1000028b0      bl    sym.imp.objc_opt_class
| || :|||   0x1000028b4      mov   x1, x0
| || :|||   0x1000028b8      mov   x0, x21
| || :|||   0x1000028bc      bl    sym.imp.objc_opt_isKindOfClass
| || :|||   0x1000028c0      mov   x23, x0
| || :|||   0x1000028c4      mov   x0, x21                             ; void *instance
| || :|||   0x1000028c8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| || :|||   0x1000028cc      mov   x21, x0
| ||,=====< 0x1000028d0      tbz   w23, 0, 0x1000029fc
| |||:|||   0x1000028d4      movi  v0.2d, 0000000000000000
| |||:|||   0x1000028d8      stp   q0, q0, [var_460h + 0x10]
| |||:|||   0x1000028dc      stp   q0, q0, [var_470h]
| |||:|||   0x1000028e0      add   x2, var_470h
| |||:|||   0x1000028e4      add   x3, var_270h
| |||:|||   0x1000028e8      mov   x0, x21
| |||:|||   0x1000028ec      mov   w4, 0x10
| |||:|||   0x1000028f0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ========< 0x1000028f4      cbz   x0, 0x1000029ac
| |||:|||   0x1000028f8      mov   x23, x0
| |||:|||   0x1000028fc      str   x20, [var_4f8h]
| |||:|||   0x100002900      mov   x26, x28
| |||:|||   0x100002904      mov   x24, 0
| |||:|||   0x100002908      mov   w28, 0
| |||:|||   0x10000290c      ldr   x8, [var_460h]                      ; [0xb0:4]=-1 ; 176
| |||:|||   0x100002910      ldr   x20, [x8]
| --------> 0x100002914      mov   x19, 0
| |||:|||   0x100002918      mov   x25, x24
| --------> 0x10000291c      ldr   x8, [var_460h]                      ; [0xb0:4]=-1 ; 176
| |||:|||   0x100002920      ldr   x8, [x8]
| |||:|||   0x100002924      cmp   x8, x20
| ========< 0x100002928      b.eq  0x100002934
| |||:|||   0x10000292c      mov   x0, x21                             ; void *instance
| |||:|||   0x100002930      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100002934      ldr   x8, [var_468h]                      ; [0xa8:4]=-1 ; 168
| |||:|||   0x100002938      ldr   x0, [x8, x19, lsl 3]                ; void *instance
| |||:|||   0x10000293c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||:|||   0x100002940      mov   x24, x0
| |||:|||   0x100002944      mov   x0, x25                             ; void *instance
| |||:|||   0x100002948      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||:|||   0x10000294c      mov   x1, x24                             ; int64_t arg3
| |||:|||   0x100002950      mov   x2, x22
| |||:|||   0x100002954      bl    sym.func.100001fa0
| |||:|||   0x100002958      orr   w28, w28, w0
| |||:|||   0x10000295c      add   x19, x19, 1
| |||:|||   0x100002960      mov   x25, x24
| |||:|||   0x100002964      subs  x23, x23, 1
| ========< 0x100002968      b.ne  0x10000291c
| |||:|||   0x10000296c      add   x2, var_470h
| |||:|||   0x100002970      add   x3, var_270h
| |||:|||   0x100002974      mov   x0, x21
| |||:|||   0x100002978      mov   w4, 0x10
| |||:|||   0x10000297c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||:|||   0x100002980      mov   x23, x0
| ========< 0x100002984      cbnz  x0, 0x100002914
| |||:|||   0x100002988      mov   x0, x24                             ; void *instance
| |||:|||   0x10000298c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||:|||   0x100002990      mov   x24, 0
| ========< 0x100002994      tbz   w28, 0, 0x1000029bc
| |||:|||   0x100002998      mov   x23, x21
| |||:|||   0x10000299c      mov   x28, x26
| |||:|||   0x1000029a0      ldr   x20, [var_4f8h]                     ; [0x18:4]=-1 ; 24
| |||:|||   0x1000029a4      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| ========< 0x1000029a8      b     0x100002a14
| --------> 0x1000029ac      mov   x24, 0
| |||:|||   0x1000029b0      mov   w25, 0
| |||:|||   0x1000029b4      mov   x23, x21
| ========< 0x1000029b8      b     0x100002230
| --------> 0x1000029bc      mov   w25, 0
| |||:|||   0x1000029c0      mov   x23, x21
| |||:|||   0x1000029c4      mov   x28, x26
| |||:|||   ; CODE XREF from sym.func.10000218c @ 0x100002dec
| --------> 0x1000029c8      ldr   x20, [var_4f8h]                     ; [0x18:4]=-1 ; 24
| ========< 0x1000029cc      b     0x100002230
| ``------> 0x1000029d0      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
|   |:|||   0x1000029d4      ldr   x19, [x19, 0xbf8]                   ; [0x10000cbf8:4]=0x1c160 ; "`\xc1\U00000001"
|   |:|||   0x1000029d8      ldr   x3, [x19]                           ; [0x10001c160:4]=0
|   |:|||                                                              ; str.tubs
|   |:|||   0x1000029dc      adrp  x0, data.100007000                  ; 0x100007000
|   |:|||   0x1000029e0      add   x0, x0, 0xe83                       ; 0x100007e83 ; "** Missing port silicon revision key(s)\n"
|   |:|||   0x1000029e4      mov   w1, 0x28                            ; '('
|   |:|||   ; CODE XREF from sym.func.10000218c @ 0x100002a84
|  .------> 0x1000029e8      mov   w2, 1
|  :|:|||   0x1000029ec      bl    sym.imp.fwrite                      ; size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
|  :|:|||   0x1000029f0      ldr   x0, [x19]                           ; [0x10001c160:4]=0
|  :|:|||                                                              ; str.tubs ; FILE *stream
|  :|:|||   0x1000029f4      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
|  :|`====< 0x1000029f8      b     0x100002224
|  :`-----> 0x1000029fc      mov   x1, x21                             ; int64_t arg3
|  :  |||   0x100002a00      mov   x2, x22
|  :  |||   0x100002a04      bl    sym.func.100001fa0
|  :  |||   0x100002a08      mov   x23, 0
|  : ,====< 0x100002a0c      cbz   w0, 0x100002a88
|  : ||||   0x100002a10      mov   x24, x21
|  : ||||   ; CODE XREF from sym.func.10000218c @ 0x1000029a8
| --------> 0x100002a14      mov   x0, x22                             ; void *instance
|  : ||||   0x100002a18      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  : ||||   0x100002a1c      mov   x0, x24                             ; void *instance
|  : ||||   0x100002a20      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  : ||||   0x100002a24      mov   x0, x23                             ; void *instance
|  : ||||   0x100002a28      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  : ||||   0x100002a2c      mov   x0, x21                             ; void *instance
|  : ||||   0x100002a30      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  : ||||   0x100002a34      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|  : ||||   0x100002a38      add   x22, x22, 0x460                     ; 0x10000c460
|  : ||||                                                              ; reloc.__CFConstantStringClassReference.10000c460
|  : ||||   0x100002a3c      mov   x0, x28
|  : ||||   0x100002a40      mov   x2, x22
|  : ||||   0x100002a44      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  : ||||   0x100002a48      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  : ||||   0x100002a4c      mov   x21, x0
|  : ||||   0x100002a50      mov   x0, x20
|  : ||||   0x100002a54      mov   x2, x22
|  : ||||   0x100002a58      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  : ||||   0x100002a5c      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  : ||||   0x100002a60      mov   x22, x0
|  :,=====< 0x100002a64      cbz   x21, 0x100002a94
| ,=======< 0x100002a68      cbnz  x22, 0x100002a94
| |:|||||   0x100002a6c      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| |:|||||   0x100002a70      ldr   x19, [x19, 0xbf8]                   ; [0x10000cbf8:4]=0x1c160 ; "`\xc1\U00000001"
| |:|||||   0x100002a74      ldr   x3, [x19]                           ; [0x10001c160:4]=0
| |:|||||                                                              ; str.tubs
| |:|||||   0x100002a78      adrp  x0, data.100007000                  ; 0x100007000
| |:|||||   0x100002a7c      add   x0, x0, 0xeac                       ; 0x100007eac ; "** Missing port OTP revision key(s) **\n"
| |:|||||   0x100002a80      mov   w1, 0x27                            ; '''
| |`======< 0x100002a84      b     0x1000029e8
| | |```--> 0x100002a88      mov   w25, 0
| | |   |   0x100002a8c      mov   x24, x21
| ========< 0x100002a90      b     0x100002230
| `-`-----> 0x100002a94      stp   x28, x20, [var_500h]
|      ,==< 0x100002a98      cbz   x21, 0x100002bb8
|      ||   0x100002a9c      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|      ||   0x100002aa0      bl    sym.imp.objc_opt_class
|      ||   0x100002aa4      mov   x1, x0
|      ||   0x100002aa8      mov   x0, x21
|      ||   0x100002aac      bl    sym.imp.objc_opt_isKindOfClass
|     ,===< 0x100002ab0      tbnz  w0, 0, 0x100002acc
|     |||   0x100002ab4      ldr   x0, [x27, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|     |||   0x100002ab8      bl    sym.imp.objc_opt_class
|     |||   0x100002abc      mov   x1, x0
|     |||   0x100002ac0      mov   x0, x21
|     |||   0x100002ac4      bl    sym.imp.objc_opt_isKindOfClass
|    ,====< 0x100002ac8      tbz   w0, 0, 0x100002c60
|    |`---> 0x100002acc      ldr   x0, [x19, 0xc10]                    ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|    | ||   0x100002ad0      bl    sym.imp.objc_opt_class
|    | ||   0x100002ad4      mov   x1, x0
|    | ||   0x100002ad8      mov   x0, x21
|    | ||   0x100002adc      bl    sym.imp.objc_opt_isKindOfClass
|    | ||   0x100002ae0      mov   x23, x0
|    | ||   0x100002ae4      mov   x0, x21                             ; void *instance
|    | ||   0x100002ae8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|    |,===< 0x100002aec      tbz   w23, 0, 0x100002bc4
|    ||||   0x100002af0      movi  v0.2d, 0000000000000000
|    ||||   0x100002af4      stp   q0, q0, [var_4a0h + 0x10]
|    ||||   0x100002af8      stp   q0, q0, [var_4b0h]
|    ||||   0x100002afc      add   x2, var_4b0h
|    ||||   0x100002b00      add   x3, var_2f0h
|    ||||   0x100002b04      str   x0, [var_508h]
|    ||||   0x100002b08      mov   w4, 0x10
|    ||||   0x100002b0c      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|   ,=====< 0x100002b10      cbz   x0, 0x100002dac
|   |||||   0x100002b14      mov   x23, x0
|   |||||   0x100002b18      mov   x25, 0
|   |||||   0x100002b1c      mov   w28, 0
|   |||||   0x100002b20      ldr   x8, [var_4a0h]                      ; [0x70:4]=-1 ; 112
|   |||||   0x100002b24      ldr   x20, [x8]
|   |||||   0x100002b28      ldr   x24, [var_508h]                     ; [0x8:4]=-1 ; 8
|  .------> 0x100002b2c      mov   x19, 0
|  :|||||   0x100002b30      mov   x26, x25
| .-------> 0x100002b34      ldr   x8, [var_4a0h]                      ; [0x70:4]=-1 ; 112
| ::|||||   0x100002b38      ldr   x8, [x8]
| ::|||||   0x100002b3c      cmp   x8, x20
| ========< 0x100002b40      b.eq  0x100002b4c
| ::|||||   0x100002b44      mov   x0, x24                             ; void *instance
| ::|||||   0x100002b48      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100002b4c      ldr   x8, [var_4a8h]                      ; [0x68:4]=-1 ; 104
| ::|||||   0x100002b50      ldr   x0, [x8, x19, lsl 3]                ; void *instance
| ::|||||   0x100002b54      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| ::|||||   0x100002b58      mov   x25, x0
| ::|||||   0x100002b5c      mov   x0, x26                             ; void *instance
| ::|||||   0x100002b60      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ::|||||   0x100002b64      mov   x1, x25                             ; int64_t arg3
| ::|||||   0x100002b68      mov   x2, x22
| ::|||||   0x100002b6c      bl    sym.func.100001fa0
| ::|||||   0x100002b70      orr   w28, w28, w0
| ::|||||   0x100002b74      add   x19, x19, 1
| ::|||||   0x100002b78      mov   x26, x25
| ::|||||   0x100002b7c      subs  x23, x23, 1
| `=======< 0x100002b80      b.ne  0x100002b34
|  :|||||   0x100002b84      add   x2, var_4b0h
|  :|||||   0x100002b88      add   x3, var_2f0h
|  :|||||   0x100002b8c      mov   x0, x24
|  :|||||   0x100002b90      mov   w4, 0x10
|  :|||||   0x100002b94      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
|  :|||||   0x100002b98      mov   x23, x0
|  `======< 0x100002b9c      cbnz  x0, 0x100002b2c
|   |||||   0x100002ba0      mov   x0, x25                             ; void *instance
|   |||||   0x100002ba4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|   |||||   0x100002ba8      mov   x24, 0
|  ,======< 0x100002bac      tbz   w28, 0, 0x100002db0
|  ||||||   0x100002bb0      ldr   x23, [var_508h]                     ; [0x8:4]=-1 ; 8
| ,=======< 0x100002bb4      b     0x100002bdc
| |||||`--> 0x100002bb8      mov   x23, 0
| ||||| |   0x100002bbc      mov   x24, 0
| |||||,==< 0x100002bc0      b     0x100002be0
| ||||`---> 0x100002bc4      mov   x24, x0
| |||| ||   0x100002bc8      mov   x1, x0                              ; int64_t arg3
| |||| ||   0x100002bcc      mov   x2, x22
| |||| ||   0x100002bd0      bl    sym.func.100001fa0
| |||| ||   0x100002bd4      mov   x23, 0
| ||||,===< 0x100002bd8      cbz   w0, 0x100002da0
| |||||||   ; CODE XREF from sym.func.10000218c @ 0x100002bb4
| `-------> 0x100002bdc      ldp   x28, x20, [var_500h]
|  ||||||   ; CODE XREF from sym.func.10000218c @ 0x100002bc0
|  ||||`--> 0x100002be0      mov   x0, x22                             ; void *instance
|  |||| |   0x100002be4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |||| |   0x100002be8      mov   x0, x24                             ; void *instance
|  |||| |   0x100002bec      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |||| |   0x100002bf0      mov   x0, x23                             ; void *instance
|  |||| |   0x100002bf4      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |||| |   0x100002bf8      mov   x0, x21                             ; void *instance
|  |||| |   0x100002bfc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |||| |   0x100002c00      adrp  x22, section.7.__DATA_CONST.__const ; 0x10000c000
|  |||| |   0x100002c04      add   x22, x22, 0x4e0                     ; 0x10000c4e0
|  |||| |                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
|  |||| |   0x100002c08      mov   x0, x28
|  |||| |   0x100002c0c      mov   x2, x22
|  |||| |   0x100002c10      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  |||| |   0x100002c14      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |||| |   0x100002c18      mov   x21, x0
|  |||| |   0x100002c1c      mov   x0, x20
|  |||| |   0x100002c20      mov   x2, x22
|  |||| |   0x100002c24      bl    stub.objc_msgSend_objectForKey:     ;  stub.objc_msgSend_objectForKey:(void)
|  |||| |   0x100002c28      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |||| |   0x100002c2c      mov   x22, x0
|  ||||,==< 0x100002c30      cbz   x21, 0x100002c70
| ,=======< 0x100002c34      cbnz  x22, 0x100002c70
| |||||||   0x100002c38      adrp  x19, section.7.__DATA_CONST.__const ; 0x10000c000
| |||||||   0x100002c3c      ldr   x19, [x19, 0xbf8]                   ; [0x10000cbf8:4]=0x1c160 ; "`\xc1\U00000001"
| |||||||   0x100002c40      ldr   x3, [x19]                           ; [0x10001c160:4]=0
| |||||||                                                              ; str.tubs ; FILE *stream
| |||||||   0x100002c44      adrp  x0, data.100007000                  ; 0x100007000
| |||||||   0x100002c48      add   x0, x0, 0xed4                       ; 0x100007ed4 ; "** Missing port UUID(s)\n" ; const void *ptr
| |||||||   0x100002c4c      mov   w1, 0x18
| |||||||   0x100002c50      mov   w2, 1
| |||||||   0x100002c54      bl    sym.imp.fwrite                      ; size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
| |||||||   0x100002c58      ldr   x0, [x19]                           ; [0x10001c160:4]=0
| |||||||                                                              ; str.tubs ; FILE *stream
| |||||||   0x100002c5c      bl    sym.imp.fflush                      ; int fflush(FILE *stream)
| ---`----> 0x100002c60      mov   x24, 0
| ||| |||   0x100002c64      mov   x23, 0
| ||| |||   0x100002c68      mov   w25, 0
| |||,====< 0x100002c6c      b     0x100002de8
| `----`--> 0x100002c70      cbz   x21, 0x100002dc0
|  |||| |   0x100002c74      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |||| |   0x100002c78      ldr   x0, [x8, 0xc10]                     ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  |||| |   0x100002c7c      bl    sym.imp.objc_opt_class
|  |||| |   0x100002c80      mov   x1, x0
|  |||| |   0x100002c84      mov   x0, x21
|  |||| |   0x100002c88      bl    sym.imp.objc_opt_isKindOfClass
|  ||||,==< 0x100002c8c      tbnz  w0, 0, 0x100002ca8
|  ||||||   0x100002c90      ldr   x0, [x27, 0xbd8]                    ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|  ||||||   0x100002c94      bl    sym.imp.objc_opt_class
|  ||||||   0x100002c98      mov   x1, x0
|  ||||||   0x100002c9c      mov   x0, x21
|  ||||||   0x100002ca0      bl    sym.imp.objc_opt_isKindOfClass
| ========< 0x100002ca4      tbz   w0, 0, 0x100002c60
|  ||||`--> 0x100002ca8      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |||| |   0x100002cac      ldr   x0, [x8, 0xc10]                     ; [0x10000cc10:4]=0x1c178 ; "x\xc1\U00000001"
|  |||| |   0x100002cb0      bl    sym.imp.objc_opt_class
|  |||| |   0x100002cb4      mov   x1, x0
|  |||| |   0x100002cb8      mov   x0, x21
|  |||| |   0x100002cbc      bl    sym.imp.objc_opt_isKindOfClass
|  |||| |   0x100002cc0      mov   x23, x0
|  |||| |   0x100002cc4      mov   x0, x21                             ; void *instance
|  |||| |   0x100002cc8      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|  |||| |   0x100002ccc      str   x0, [var_508h]
|  ||||,==< 0x100002cd0      tbz   w23, 0, 0x100002dcc
|  ||||||   0x100002cd4      movi  v0.2d, 0000000000000000
|  ||||||   0x100002cd8      stp   q0, q0, [var_4e0h + 0x10]
|  ||||||   0x100002cdc      stp   q0, q0, [var_4f0h]
|  ||||||   0x100002ce0      add   x2, var_4f0h
|  ||||||   0x100002ce4      add   x3, var_370h
|  ||||||   0x100002ce8      ldr   x0, [var_508h]                      ; [0x8:4]=-1 ; 8
|  ||||||   0x100002cec      mov   w4, 0x10
|  ||||||   0x100002cf0      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| ,=======< 0x100002cf4      cbz   x0, 0x100002dac
| |||||||   0x100002cf8      mov   x23, x0
| |||||||   0x100002cfc      mov   x25, 0
| |||||||   0x100002d00      mov   w27, 0
| |||||||   0x100002d04      ldr   x8, [var_4e0h]                      ; [0x30:4]=-1 ; 48
| |||||||   0x100002d08      ldr   x20, [x8]
| |||||||   0x100002d0c      ldr   x24, [var_508h]                     ; [0x8:4]=-1 ; 8
| --------> 0x100002d10      mov   x19, 0
| |||||||   0x100002d14      mov   x26, x25
| --------> 0x100002d18      ldr   x8, [var_4e0h]                      ; [0x30:4]=-1 ; 48
| |||||||   0x100002d1c      ldr   x8, [x8]
| |||||||   0x100002d20      cmp   x8, x20
| ========< 0x100002d24      b.eq  0x100002d30
| |||||||   0x100002d28      mov   x0, x24                             ; void *instance
| |||||||   0x100002d2c      bl    sym.imp.objc_enumerationMutation    ; void objc_enumerationMutation(void *instance)
| --------> 0x100002d30      ldr   x8, [var_4e8h]                      ; [0x28:4]=-1 ; 40
| |||||||   0x100002d34      ldr   x0, [x8, x19, lsl 3]                ; void *instance
| |||||||   0x100002d38      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
| |||||||   0x100002d3c      mov   x25, x0
| |||||||   0x100002d40      mov   x0, x26                             ; void *instance
| |||||||   0x100002d44      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100002d48      mov   x1, x25                             ; int64_t arg3
| |||||||   0x100002d4c      mov   x2, x22
| |||||||   0x100002d50      bl    sym.func.100002e04
| |||||||   0x100002d54      orr   w27, w27, w0
| |||||||   0x100002d58      add   x19, x19, 1
| |||||||   0x100002d5c      mov   x26, x25
| |||||||   0x100002d60      subs  x23, x23, 1
| ========< 0x100002d64      b.ne  0x100002d18
| |||||||   0x100002d68      add   x2, var_4f0h
| |||||||   0x100002d6c      add   x3, var_370h
| |||||||   0x100002d70      mov   x0, x24
| |||||||   0x100002d74      mov   w4, 0x10
| |||||||   0x100002d78      bl    stub.objc_msgSend_countByEnumeratingWithState:objects:count: ;  stub.objc_msgSend_countByEnumeratingWithState:objects:count:(void)
| |||||||   0x100002d7c      mov   x23, x0
| ========< 0x100002d80      cbnz  x0, 0x100002d10
| |||||||   0x100002d84      mov   x0, x25                             ; void *instance
| |||||||   0x100002d88      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| |||||||   0x100002d8c      mov   x24, 0
| ========< 0x100002d90      tbz   w27, 0, 0x100002db0
| |||||||   0x100002d94      ldr   x23, [var_508h]                     ; [0x8:4]=-1 ; 8
| |||||||   0x100002d98      str   x24, [var_508h]
| ========< 0x100002d9c      b     0x100002de0
| ||||`---> 0x100002da0      mov   w25, 0
| |||| ||   0x100002da4      mov   x21, x24
| ||||,===< 0x100002da8      b     0x100002de8
| `-`-----> 0x100002dac      mov   x24, 0
| -`------> 0x100002db0      mov   w25, 0
|    ||||   0x100002db4      ldr   x21, [var_508h]                     ; [0x8:4]=-1 ; 8
|    ||||   0x100002db8      mov   x23, x21
|   ,=====< 0x100002dbc      b     0x100002de8
| --------> 0x100002dc0      mov   x23, 0
|   |||||   0x100002dc4      str   xzr, [var_508h]
|  ,======< 0x100002dc8      b     0x100002de0
|  ||||`--> 0x100002dcc      ldr   x1, [var_508h]                      ; [0x8:4]=-1 ; 8 ; int64_t arg3
|  |||| |   0x100002dd0      mov   x2, x22
|  |||| |   0x100002dd4      bl    sym.func.100002e04
|  |||| |   0x100002dd8      mov   x23, 0
|  ||||,==< 0x100002ddc      cbz   w0, 0x100002df0
|  ||||||   ; CODE XREFS from sym.func.10000218c @ 0x100002d9c, 0x100002dc8
| -`------> 0x100002de0      mov   w25, 1
|   |||||   0x100002de4      ldr   x24, [var_508h]                     ; [0x8:4]=-1 ; 8
|   |||||   ; CODE XREFS from sym.func.10000218c @ 0x100002c6c, 0x100002da8, 0x100002dbc, 0x100002dfc
|  .```---> 0x100002de8      ldr   x28, [var_500h]                     ; [0x10:4]=-1 ; 16
| ========< 0x100002dec      b     0x1000029c8
|  :   `--> 0x100002df0      mov   w25, 0
|  :    |   0x100002df4      ldr   x21, [var_508h]                     ; [0x8:4]=-1 ; 8
|  :    |   0x100002df8      mov   x24, x21
|  `======< 0x100002dfc      b     0x100002de8
\       `-> 0x100002e00      bl    sym.imp.__stack_chk_fail            ; void __stack_chk_fail(void)
