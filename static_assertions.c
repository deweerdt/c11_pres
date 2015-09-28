char storage[1];
struct my_struct {
	int i;
};

/*
 *  Gateway code:
 *  void workflow_core_list_init(void)
 *  {
 *     XASSERTN(sizeof(struct workflow_core_list_ctx) <= WF_FUNCTION_STORAGE);
 *  }
 *
 */

int main(void)
{
	struct my_struct *s;
	_Static_assert(sizeof(s) <= sizeof(storage), "Storage is too small");
	s = (void *)storage;
	s->i = 123;
	return s->i;
}
