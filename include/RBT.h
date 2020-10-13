#include <iostream>
#include <vector>
using namespace std;

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
  struct RBT_node *lc_node;

  /** Puntero al nodo hijo derecho */
  struct RBT_node *rc_node;

  /** Puntero al nodo padre */
  struct RBT_node *p_node;

  /** Número flotante asociado al nodo */
  float value;

  /** Letra que indica el color asociado al nodo */
  char color;

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
  std::vector <float> const &in_number_list,
  int size,
  struct RBT_node **new_root_node);

void RBT_print(
  struct RBT_node *new_root_node,
  string indent,
  bool last);

struct RBT_node* RBT_node_add_fix(
  struct RBT_node* in_root,
  struct RBT_node* new_node);


/**
 * RBT_right_rotate
 * Toma un nodo sobre el cual hacer la rotación, y rota hacia la derecha en torno a ese nodo.
 * Retorna la raíz del arbol por si esta cambió.
 *
 * @param [in]  in_root         es el nodo raíz del árbol
 * @param [in]  rotation_node   es el nodo sobre el cual hacer la rotación
 *
 * @returns struct RBT_node*   un puntero hacia el nodo raíz
 *                             
 */
struct RBT_node* RBT_right_rotate(
  struct RBT_node*  in_root, 
  struct RBT_node*  rotation_node);


/**
 * RBT_left_rotate
 * Toma un nodo sobre el cual hacer la rotación, y rota hacia la izquierda en torno a ese nodo.
 * Retorna la raíz del arbol por si esta cambió.
 *
 * @param [in]  in_root         es el nodo raíz del árbol
 * @param [in]  rotation_node   es el nodo sobre el cual hacer la rotación
 *
 * @returns struct RBT_node*   un puntero hacia el nodo raíz
 *                             
 */
struct RBT_node* RBT_left_rotate(
  struct RBT_node*  in_root, 
  struct RBT_node*  rotation_node);


/**
 * RBT_Transplant
 * Realiza la operación de cambiar un nodo por otro.
 * Retorna la raíz del arbol por si esta cambió.
 *
 * @param [in]  in_root           es el nodo raíz del árbol
 * @param [in]  node_to_replace   es el nodo que va a ser reemplazado
 * @param [in]  replacing_node    es el nodo que va a reemplazar a otro
 *
 * @returns struct RBT_node*      un puntero hacia el nodo raíz
 *                             
 */
struct RBT_node* RBT_Transplant(
  struct RBT_node* in_root, 
  struct RBT_node* node_to_replace, 
  struct RBT_node* replacing_node);


/**
 * get_min-address
 * Recibe un nodo, revisa si es hijo derecho o izquierdo y retorna su dirección de memoria.
 *
 * @param [in]  min            es el nodo a revisar
 *
 * @returns struct RBT_node*   un puntero al nodo requerido
 *                             
 */
struct RBT_node* get_min_address(
  struct RBT_node min);


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
  struct RBT_node  *in_root,
  struct RBT_node  *new_node,
  struct RBT_node **new_root);


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
  struct RBT_node*  in_root,
  float  value_to_remove,
  struct RBT_node *new_root);


/**
 * RBT_node_remove_fixup
 * Realiza las correcciones necesarias para mantener las propiedades de un RBT.
 * Devuelve el nuevo root si este cambió.
 *
 * @param [in]  in_root        es el nodo raíz original del árbol
 * @param [in]  node_x         es el nodo que se marca como "double black" para hacer las correcciones
 * 
 *
 * @returns struct RBT_node*   un puntero a la raíz del árbol
 *                             
 */
struct RBT_node* RBT_remove_fixup(
  struct RBT_node* in_root, 
  struct RBT_node* node_x);


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
  struct RBT_node  *in_root,
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
  struct RBT_node  *in_root,
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
  struct RBT_node  *in_root,
  struct RBT_node *min_node);



