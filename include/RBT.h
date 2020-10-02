// NOTA: sustituir <abreviatura> por la abreviatura correspondiente: avl (AVL)
// para AVL tree, o rbt (RBT) para Red Black Tree.

/**
 * Códigos de error
 */
enum RBT_error_codes {
  RBT_SUCCESS       = 0,
  RBT_INVALID_PARAM = -1,
  RBT_OUT_OF_RANGE  = -2,
  RBT_TIMEOUT       = -3,
  RBT_NOT_FOUND     = -4,
  // Pueden añadir más
};

/**
 * Struct que define un nodo de la estructura de datos
 */
struct RBT_node {
  /** Puntero al nodo hijo izquierdo */
   RBT_node *lc_node;

  /** Puntero al nodo hijo derecho */
  RBT_node *rc_node;

  /** Puntero al nodo padre */
 RBT_node *p_node;

  /** Número flotante asociado al nodo */
  int value;

  /** Letra que indica el color asociado al nodo */
  int color;

  bool first_node;

};


/**
 * RBT_create
 * Toma una lista de números flotantes, y crea la estructura de datos deseada.
 * Retorna el nodo raíz del árbol.
 *
 * @param [in]  in_number_list es la lista de números flotantes de entrada
 * @param [out] new_root_node  es el puntero al nodo raíz del árbol creado
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int RBT_create(
  float in_number_list[],
  RBT_node* new_root_node);


/**
 * RBT_node_add
 * Toma un nodo y lo inserta en la estructura de datos.
 * Una nueva raíz puede ser obtenida.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [in]  new_node  es el nodo con el número flotante por insertar
 * @param [out] new_root  es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int RBT_node_add(
 RBT_node  in_root,
 RBT_node  new_node,
 RBT_node new_root);


/**
 * RBT_node_remove
 * Toma un nodo arbitrario, lo busca y lo elimina de la estructura de datos.
 * Da error si el nodo no pertenece al árbol.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  node_to_remove es el nodo por eliminar
 * @param [out] new_root       es el puntero al nuevo nodo raíz del árbol
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int RBT_node_remove(
  struct RBT_node  in_root,
  struct RBT_node  node_to_remove,
  struct RBT_node *new_root);


/**
 * RBT_search
 * Toma un número flotante, lo busca y se devuelve el nodo al que pertenece.
 * Si existieran varios nodos con el mismo valor, se devuelve cualquiera.
 * Da error si el valor no existe en ningún nodo.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  num            es el número flotante por buscar
 * @param [out] found_node     es el nodo encontrado que contiene el valor
 *
 * @returns error_code         un código de error indicando el éxito o error
 *                             de la función
 */
int RBT_search(
  struct RBT_node  in_root,
  float                      num,
  struct RBT_node *found_node);


/**
 * RBT_max_get
 * Se obtiene el nodo que contenga el valor máximo en todo el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] max_node  es el nodo encontrado que contiene el valor máximo
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int RBT_max_get(
  struct RBT_node  in_root,
  struct RBT_node *max_node);


/**
 * RBT_min_get
 * Se obtiene el nodo que contenga el valor mínimo en todo el árbol.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 * @param [out] min_node  es el nodo encontrado que contiene el valor mínimo
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int RBT_min_get(
  struct RBT_node  in_root,
  struct RBT_node *min_node);


/**
 * RBT_print
 * Se imprime el árbol en terminal.
 *
 * @param [in]  in_root   es el nodo raíz original del árbol
 *
 * @returns error_code    un código de error indicando el éxito o error
 *                        de la función
 */
int RBT_print(
  struct RBT_node  in_root);
