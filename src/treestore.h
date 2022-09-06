//
// Created by tspradli on 9/4/22.
//

#ifndef JSONTREE_TREESTORE_H
#define JSONTREE_TREESTORE_H

#include <gtkmm/treestore.h>


class JsonTreeStore : public Gtk::TreeStore {
public:
    JsonTreeStore(Gtk::TreeStore::BaseObjectType *cobject);
    ~JsonTreeStore() override;

private:

};


#endif //JSONTREE_TREESTORE_H
