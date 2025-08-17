__int64 __fastcall sub_1400026A0(__int64 a1, _QWORD *a2, _DWORD *a3)
{
  _QWORD *v3; // rdi
  NTSTATUS v7; // eax
  unsigned int v9; // ecx
  HANDLE CurrentProcessId; // rax
  __int64 v11; // r8
  __int64 v12; // rax
  char v13; // al
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rcx
  char v17; // al
  char v18; // al
  __int64 v19; // rax
  void *v20; // r14
  __int64 v21; // rcx
  __int64 v23; // rbx
  int v24; // eax
  char v25; // al
  unsigned int v26; // ebx
  __int64 v27; // rax
  _DWORD *v28; // rax

  v3 = *(_QWORD **)(a1 + 64);
  v7 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(v3 + 3), a2, File, 1u, 0x20u);
  if ( v7 < 0 )
    return sub_140004550(a2, (unsigned int)v7, 0i64);
  v9 = a3[6];
  if ( v9 <= 0x2D1080 )
  {
    if ( v9 == 2953344 )
      goto LABEL_35;
    if ( v9 != 315396 && v9 != 315412 )
    {
      if ( v9 == 508004 )
        goto LABEL_16;
      if ( v9 != 1933636 )
        goto LABEL_56;
      CurrentProcessId = PsGetCurrentProcessId();
      if ( !qword_140008FC0
        || *(_QWORD *)(qword_140008FC0 + 8) != 4i64
        || *(_QWORD *)(qword_140008FC0 + 16) != 4i64
        || !*(_BYTE *)(qword_140008FC0 + 24)
        || !(*(unsigned __int8 (__fastcall **)(HANDLE))(qword_140008FC0 + 56))(CurrentProcessId) )
      {
LABEL_16:
        if ( (v3[8] & 2) != 0 )
        {
          v11 = a2[3];
          if ( !v11 )
            goto LABEL_35;
          if ( a3[4] <= 0x20u )
          {
            if ( (unsigned __int8)sub_1400017A0(v3, a1, *(_QWORD *)(v11 + 8), *(_QWORD *)(v11 + 16), a2) )
            {
              IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v3 + 3), a2, 0x20u);
              return 259i64;
            }
LABEL_35:
            if ( (v3[8] & 0x20) == 0 && a2[3] && a3[2] >= 0xCu )
              return sub_140004700(*v3, a2, sub_140002650, v3);
          }
        }
LABEL_56:
        v26 = sub_140004670(a1, a2);
        IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v3 + 3), a2, 0x20u);
        return v26;
      }
      return sub_140004550(a2, 3221225506i64, 0i64);
    }
    if ( (v3[8] & 1) == 0 )
      goto LABEL_56;
    v12 = a2[3];
    if ( !v12 )
      goto LABEL_56;
    if ( a3[2] < 0x38u )
      goto LABEL_56;
    v13 = *(_BYTE *)(v12 + 36);
    if ( v13 != 42 && v13 != 81 )
      goto LABEL_56;
    v14 = qword_140008FC0;
    v15 = *((unsigned int *)v3 + 21);
    if ( !qword_140008FC0
      || *(_QWORD *)(qword_140008FC0 + 8) != 4i64
      || *(_QWORD *)(qword_140008FC0 + 16) != 4i64
      || !*(_BYTE *)(qword_140008FC0 + 24) )
    {
      goto LABEL_30;
    }
    LODWORD(v15) = v15 | 0x10000;
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(qword_140008FC0 + 72))(v15) )
    {
      v14 = qword_140008FC0;
LABEL_30:
      v16 = *((unsigned int *)v3 + 21);
      if ( !v14 || *(_QWORD *)(v14 + 8) != 4i64 || *(_QWORD *)(v14 + 16) != 4i64 || !*(_BYTE *)(v14 + 24) )
        goto LABEL_56;
      LODWORD(v16) = v16 | 0x10000;
      v17 = (*(__int64 (__fastcall **)(__int64))(v14 + 80))(v16);
LABEL_72:
      if ( v17 )
        goto LABEL_56;
    }
LABEL_73:
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v3 + 3), a2, 0x20u);
    return sub_140004550(a2, 3221225506i64, 0i64);
  }
  if ( v9 != 2954240 )
  {
    if ( ((v9 - 4210952) & 0xFFFF7FFF) != 0 )
      goto LABEL_56;
    v18 = *((_BYTE *)v3 + 64);
    if ( (v18 & 4) == 0 || !a2[3] )
      goto LABEL_56;
    if ( (v18 & 0x40) == 0 )
    {
      if ( *((_DWORD *)v3 + 20) >= 0x200u )
        goto LABEL_56;
      v19 = sub_140003700((PDEVICE_OBJECT)v3[1]);
      v20 = (void *)v19;
      if ( !v19 )
      {
        _InterlockedIncrement((volatile signed __int32 *)v3 + 20);
        goto LABEL_56;
      }
      v21 = -1i64;
      while ( *(_WORD *)(v19 + 2 * v21++ + 2) != 0 )
        ;
      v23 = sub_140003B00(v19, (unsigned int)(2 * v21));
      ExFreePoolWithTag(v20, 0x54646576u);
      *((_BYTE *)v3 + 64) |= 0x40u;
      v3[11] = v23;
    }
    v24 = a3[6];
    if ( v24 == 4210952 )
    {
      if ( qword_140008FC0
        && *(_QWORD *)(qword_140008FC0 + 8) == 4i64
        && *(_QWORD *)(qword_140008FC0 + 16) == 4i64
        && *(_BYTE *)(qword_140008FC0 + 24) )
      {
        v25 = (*(__int64 (__fastcall **)(_QWORD))(qword_140008FC0 + 88))(v3[11]);
      }
      else
      {
        v25 = 1;
      }
      if ( v25 )
        goto LABEL_56;
      goto LABEL_73;
    }
    if ( v24 != 4243720 )
      goto LABEL_56;
    v27 = qword_140008FC0;
    if ( qword_140008FC0
      && *(_QWORD *)(qword_140008FC0 + 8) == 4i64
      && *(_QWORD *)(qword_140008FC0 + 16) == 4i64
      && *(_BYTE *)(qword_140008FC0 + 24) )
    {
      if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(qword_140008FC0 + 88))(v3[11]) )
        goto LABEL_73;
      v27 = qword_140008FC0;
    }
    if ( !v27 || *(_QWORD *)(v27 + 8) != 4i64 || *(_QWORD *)(v27 + 16) != 4i64 || !*(_BYTE *)(v27 + 24) )
      goto LABEL_56;
    v17 = (*(__int64 (__fastcall **)(_QWORD))(v27 + 96))(v3[11]);
    goto LABEL_72;
  }
  if ( (v3[8] & 8) != 0 )
    goto LABEL_56;
  v28 = (_DWORD *)a2[3];
  if ( !v28 || a3[4] < 0xCu || a3[2] < 0x28u || *v28 || v28[1] )
    goto LABEL_56;
  return sub_140004700(*v3, a2, sub_140002AD0, v3);
}