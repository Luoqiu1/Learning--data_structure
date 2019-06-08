
Status MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
//	int ja,jb,jc;
//	for(ja=jb=jc=0;ja<La.length&&jb<Lb.length;){
//		if(La.elem[ja]<Lb.elem[jb]){
//			Lc.elem[jc++]=La.elem[ja++];
//		}
//		else{
//			Lc.elem[jc++]=Lb.elem[jb++];
//		}
//	}

	int ja,jb,jc;ja=jb=jc=0;
	while(ja<La.length&&jb<Lb.length){
		if(La.elem[ja]<Lb.elem[jb]){
			Lc.elem[jc++]=La.elem[ja++];
		}
		else{
			Lc.elem[jc++]=Lb.elem[jb++];
		}
	}

	while(ja<La.length){
		Lc.elem[jc++]=La.elem[ja++];
	}
	while(jb<Lb.length){
	//	Lc.elem[jc++]=La.elem[jb++];
		// 改没改全。。仔细
		 Lc.elem[jc++]=Lb.elem[jb++];
	}
	return Ok;
 } 
